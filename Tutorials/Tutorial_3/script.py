from __future__ import annotations

import argparse
import csv
import os
import re
import subprocess
import sys
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent
SOURCE_MUSEUM_1 = BASE_DIR / "museum1.csv"
SOURCE_MUSEUM_2 = BASE_DIR / "museum2.csv"

# Match the working local MySQL setup used in the existing reference importer.
DEFAULT_DB_CONFIG = {
    "host": "localhost",
    "port": 3306,
    "user": "sheikh",
    "password": "miniso123",
    "database": "demo",
    "table": "museum",
}

OUTPUT_COLUMNS = [
    "Mus_Name",
    "Mus_ID",
    "Obj_Name",
    "Obj_ID",
    "Obj_Len",
    "Obj_Wid",
    "Obj_height",
    "Obj_Mat",
    "Obj_GeoRef",
    "Obj_country",
    "Per_Name",
    "Acq_year",
    "Acq_month",
    "Acq_date",
]

NUMERIC_COLUMNS = {
    "Obj_Len",
    "Obj_Wid",
    "Obj_height",
    "Acq_year",
    "Acq_month",
    "Acq_date",
}


def clean_text(value: str | None) -> str | None:
    if value is None:
        return None

    value = value.strip()
    if value in {"", "-", "[NI]"}:
        return None
    return value


def clean_material(value: str | None) -> str | None:
    value = clean_text(value)
    if not value:
        return None

    # Strip placeholder tags such as "<unbestimmt>" while keeping the known part.
    value = re.sub(r"\s*<[^>]+>", "", value).strip()
    return value or None


def parse_dimensions(raw_value: str | None) -> tuple[str | None, str | None, str | None]:
    raw_value = clean_text(raw_value)
    if not raw_value:
        return None, None, None

    numbers = re.findall(r"\d+(?:\.\d+)?", raw_value)
    numbers = numbers[:3]
    numbers.extend([None] * (3 - len(numbers)))
    return tuple(numbers)


def parse_date_parts(raw_value: str | None) -> tuple[str | None, str | None, str | None]:
    raw_value = clean_text(raw_value)
    if not raw_value:
        return None, None, None

    if re.fullmatch(r"\d{4}-\d{2}-\d{2}", raw_value):
        year, month, day = raw_value.split("-")
        return year, str(int(month)), str(int(day))

    year_match = re.search(r"\d{4}", raw_value)
    if year_match:
        return year_match.group(0), None, None

    return None, None, None


def normalize_museum1_rows(path: Path) -> list[dict[str, str | None]]:
    rows: list[dict[str, str | None]] = []

    with path.open(newline="", encoding="utf-8") as handle:
        reader = csv.DictReader(handle)
        for source_row in reader:
            obj_len, obj_wid, obj_height = parse_dimensions(source_row["dimensions_raw"])
            acq_year, acq_month, acq_date = parse_date_parts(source_row["accession_date"])

            # Keep the merged column layout already used in the assignment files.
            rows.append(
                {
                    "Mus_Name": clean_text(source_row["museum_name"]),
                    "Mus_ID": clean_text(source_row["source_sort_number"]),
                    "Obj_Name": clean_text(source_row["object_name"]),
                    "Obj_ID": clean_text(source_row["object_number"]),
                    "Obj_Len": obj_len,
                    "Obj_Wid": obj_wid,
                    "Obj_height": obj_height,
                    "Obj_Mat": clean_material(source_row["material_raw"]),
                    "Obj_GeoRef": clean_text(source_row["culture_raw"]),
                    "Obj_country": clean_text(source_row["title"]),
                    "Per_Name": clean_text(source_row["acquirer_name"]),
                    "Acq_year": acq_year,
                    "Acq_month": acq_month,
                    "Acq_date": acq_date,
                }
            )

    return rows


def normalize_museum2_rows(path: Path) -> list[dict[str, str | None]]:
    rows: list[dict[str, str | None]] = []

    with path.open(newline="", encoding="utf-8") as handle:
        reader = csv.DictReader(handle)
        for source_row in reader:
            obj_len, obj_wid, obj_height = parse_dimensions(source_row["dimensions_raw"])
            acq_year, acq_month, acq_date = parse_date_parts(source_row["acquisition_date_text"])

            rows.append(
                {
                    "Mus_Name": clean_text(source_row["museum_name"]),
                    "Mus_ID": None,
                    "Obj_Name": clean_text(source_row["object_name"]),
                    "Obj_ID": clean_text(source_row["object_number"]),
                    "Obj_Len": obj_len,
                    "Obj_Wid": obj_wid,
                    "Obj_height": obj_height,
                    "Obj_Mat": clean_material(source_row["material_raw"]),
                    "Obj_GeoRef": clean_text(source_row["origin_raw"]),
                    "Obj_country": None,
                    "Per_Name": clean_text(source_row["acquirer_name"]),
                    "Acq_year": acq_year,
                    "Acq_month": acq_month,
                    "Acq_date": acq_date,
                }
            )

    return rows


def build_rows() -> list[dict[str, str | None]]:
    return normalize_museum1_rows(SOURCE_MUSEUM_1) + normalize_museum2_rows(SOURCE_MUSEUM_2)


def write_merged_csv(rows: list[dict[str, str | None]], output_path: Path) -> None:
    with output_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.DictWriter(handle, fieldnames=OUTPUT_COLUMNS)
        writer.writeheader()

        for row in rows:
            writer.writerow(
                {
                    column: "" if row[column] is None else row[column]
                    for column in OUTPUT_COLUMNS
                }
            )


def sql_value(column: str, value: str | None) -> str:
    if value is None:
        return "NULL"

    if column in NUMERIC_COLUMNS:
        return value

    return "'" + value.replace("'", "''") + "'"


def build_import_sql(rows: list[dict[str, str | None]], database: str, table: str) -> str:
    insert_rows: list[str] = []
    for row in rows:
        values = ", ".join(sql_value(column, row[column]) for column in OUTPUT_COLUMNS)
        insert_rows.append(f"    ({values})")

    columns = ", ".join(OUTPUT_COLUMNS)
    values_sql = ",\n".join(insert_rows)

    return f"""DROP DATABASE IF EXISTS `{database}`;
CREATE DATABASE `{database}` CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE `{database}`;

DROP TABLE IF EXISTS `{table}`;
CREATE TABLE `{table}` (
    `Mus_Name` VARCHAR(100) NOT NULL,
    `Mus_ID` VARCHAR(50) NULL,
    `Obj_Name` VARCHAR(255) NOT NULL,
    `Obj_ID` VARCHAR(50) NOT NULL,
    `Obj_Len` DECIMAL(10, 2) NULL,
    `Obj_Wid` DECIMAL(10, 2) NULL,
    `Obj_height` DECIMAL(10, 2) NULL,
    `Obj_Mat` TEXT NULL,
    `Obj_GeoRef` VARCHAR(255) NULL,
    `Obj_country` VARCHAR(255) NULL,
    `Per_Name` VARCHAR(255) NULL,
    `Acq_year` SMALLINT NULL,
    `Acq_month` TINYINT NULL,
    `Acq_date` TINYINT NULL,
    PRIMARY KEY (`Obj_ID`)
);

INSERT INTO `{table}` ({columns}) VALUES
{values_sql};
"""


def load_into_mysql(
    sql_text: str,
    *,
    host: str,
    port: int,
    user: str,
    password: str,
) -> None:
    command = [
        "mysql",
        f"--host={host}",
        f"--port={port}",
        f"--user={user}",
        "--default-character-set=utf8mb4",
    ]

    environment = os.environ.copy()
    if password:
        environment["MYSQL_PWD"] = password

    completed = subprocess.run(
        command,
        input=sql_text,
        text=True,
        capture_output=True,
        env=environment,
        check=False,
    )

    if completed.returncode != 0:
        details = (completed.stderr or completed.stdout).strip()
        raise RuntimeError(details or f"mysql exited with status {completed.returncode}")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Clean the museum source CSV files and load them into MySQL."
    )
    parser.add_argument(
        "--output-csv",
        type=Path,
        default=BASE_DIR / "museum.csv",
        help="Path for the merged CSV output.",
    )
    parser.add_argument(
        "--output-sql",
        type=Path,
        help="Optional path to write the generated MySQL bootstrap SQL.",
    )
    parser.add_argument(
        "--skip-db-load",
        action="store_true",
        help="Only generate the cleaned CSV/SQL files and skip loading MySQL.",
    )
    parser.add_argument(
        "--database",
        default=os.getenv("MUSEUM_DB_NAME", DEFAULT_DB_CONFIG["database"]),
        help="Target MySQL database name.",
    )
    parser.add_argument(
        "--table",
        default=os.getenv("MUSEUM_TABLE", DEFAULT_DB_CONFIG["table"]),
        help="Target MySQL table name.",
    )
    parser.add_argument(
        "--mysql-host",
        default=os.getenv("MUSEUM_DB_HOST", DEFAULT_DB_CONFIG["host"]),
        help="MySQL host name.",
    )
    parser.add_argument(
        "--mysql-port",
        type=int,
        default=int(os.getenv("MUSEUM_DB_PORT", str(DEFAULT_DB_CONFIG["port"]))),
        help="MySQL port.",
    )
    parser.add_argument(
        "--mysql-user",
        default=os.getenv("MUSEUM_DB_USER", DEFAULT_DB_CONFIG["user"]),
        help="MySQL user name.",
    )
    parser.add_argument(
        "--mysql-password",
        default=os.getenv("MUSEUM_DB_PASSWORD", DEFAULT_DB_CONFIG["password"]),
        help="MySQL password.",
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    rows = build_rows()
    sql_text = build_import_sql(rows, args.database, args.table)

    write_merged_csv(rows, args.output_csv)
    print(f"Wrote {len(rows)} cleaned rows to {args.output_csv}")

    if args.output_sql:
        args.output_sql.write_text(sql_text, encoding="utf-8")
        print(f"Wrote bootstrap SQL to {args.output_sql}")

    if args.skip_db_load:
        print("Skipped MySQL import because --skip-db-load was provided.")
        return 0

    try:
        load_into_mysql(
            sql_text,
            host=args.mysql_host,
            port=args.mysql_port,
            user=args.mysql_user,
            password=args.mysql_password,
        )
    except FileNotFoundError:
        print("The mysql client is not installed or not available in PATH.", file=sys.stderr)
        return 1
    except RuntimeError as error:
        print("MySQL import failed.", file=sys.stderr)
        print(str(error), file=sys.stderr)
        print(
            "Set MUSEUM_DB_USER/MUSEUM_DB_PASSWORD or pass --mysql-user/--mysql-password.",
            file=sys.stderr,
        )
        return 1

    print(f"Loaded {len(rows)} rows into {args.database}.{args.table}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
