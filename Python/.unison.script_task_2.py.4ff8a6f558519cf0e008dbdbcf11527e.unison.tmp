import pandas as pd
import os
import mysql.connector
from mysql.connector import Error

# =========================================
# CONFIG
# =========================================
# EXCEL_FILE = "sample.xlsx"
BASE_DIR = os.path.dirname(os.path.abspath(__file__))
EXCEL_FILE = os.path.join(BASE_DIR, "sample.xlsx")

DB_CONFIG = {
    "host": "localhost",
    "user": "sheikh",          # change if needed
    "password": "miniso123",  # change if needed
    "database": "PHARMA_DB_TASK2"
}

# =========================================
# HELPERS
# =========================================
def clean_str(value):
    if pd.isna(value):
        return None
    s = str(value).strip()
    return s if s else None

def clean_date(value):
    if pd.isna(value):
        return None
    try:
        return pd.to_datetime(value).date()
    except Exception:
        return None

def clean_int(value):
    if pd.isna(value):
        return None
    try:
        return int(value)
    except Exception:
        return None

def unique_non_empty(values):
    seen = set()
    result = []
    for v in values:
        val = clean_str(v)
        if val and val not in seen:
            seen.add(val)
            result.append(val)
    return result

# =========================================
# MAIN
# =========================================
def main():
    df = pd.read_excel(EXCEL_FILE, sheet_name="Sheet1")

    # Expected columns from the provided Excel
    # [
    # 'drug name', 'side effect', 'side effect.1', 'side effect.2', 'side effect.3', 'side effect.4',
    # 'interacts with', 'interacts with.1', 'interacts with.2',
    # 'disease name', 'disease category', 'drug category',
    # 'product name', 'company name',
    # 'clinical trial title', 'clinical trial start date', 'clinical trial completion date',
    # 'clinical trial participants', 'clinical trial status',
    # 'clinical trial condition', 'clinical trial condition.1', 'clinical trial address',
    # 'clinical trial institution', 'clinical trial address.1',
    # 'clinical trial main researcher', 'clinical trial condition.2'
    # ]

    # Containers
    researchers = set()
    drugs = {}
    diseases = {}
    side_effects = set()
    products = {}
    trials = {}

    drug_interactions = set()
    trial_conditions = set()
    studies = set()
    treats = set()
    has_side_effect = set()

    # -----------------------------------------
    # READ ROWS
    # -----------------------------------------
    for _, row in df.iterrows():
        drug_name = clean_str(row["drug name"])
        if not drug_name:
            continue

        # DRUG
        drug_category = clean_str(row["drug category"])
        if drug_name not in drugs:
            drugs[drug_name] = drug_category
        elif not drugs[drug_name] and drug_category:
            drugs[drug_name] = drug_category

        # DISEASE
        disease_name = clean_str(row["disease name"])
        disease_category = clean_str(row["disease category"])
        if disease_name:
            if disease_name not in diseases:
                diseases[disease_name] = disease_category
            elif not diseases[disease_name] and disease_category:
                diseases[disease_name] = disease_category
            treats.add((drug_name, disease_name))

        # SIDE EFFECTS
        side_effect_cols = [
            "side effect", "side effect.1", "side effect.2",
            "side effect.3", "side effect.4"
        ]
        for eff in unique_non_empty([row[c] for c in side_effect_cols]):
            side_effects.add(eff)
            has_side_effect.add((drug_name, eff))

        # INTERACTIONS
        interaction_cols = ["interacts with", "interacts with.1", "interacts with.2"]
        for other_drug in unique_non_empty([row[c] for c in interaction_cols]):
            if other_drug == drug_name:
                continue

            # make sure interacting drug also exists in DRUG
            if other_drug not in drugs:
                drugs[other_drug] = None

            # store in canonical sorted form to avoid duplicates like A-B and B-A
            pair = tuple(sorted([drug_name, other_drug]))
            drug_interactions.add(pair)

        # PRODUCT
        product_name = clean_str(row["product name"])
        company_name = clean_str(row["company name"])
        if product_name:
            products[product_name] = {
                "company_name": company_name,
                "drug_name": drug_name
            }

        # RESEARCHER + CLINICAL TRIAL
        trial_title = clean_str(row["clinical trial title"])
        researcher_name = clean_str(row["clinical trial main researcher"])

        if researcher_name:
            researchers.add(researcher_name)

        if trial_title:
            if trial_title not in trials:
                trials[trial_title] = {
                    "clinical_trial_status": clean_str(row["clinical trial status"]),
                    "clinical_trial_start_date": clean_date(row["clinical trial start date"]),
                    "clinical_trial_completion_date": clean_date(row["clinical trial completion date"]),
                    "clinical_trial_participants": clean_int(row["clinical trial participants"]),
                    "trial_country": clean_str(row["clinical trial address"]),
                    "trial_institution": clean_str(row["clinical trial institution"]),
                    "trial_department": clean_str(row["clinical trial address.1"]),
                    "researcher_name": researcher_name
                }
            else:
                # fill missing values if a later row has them
                for key, new_value in {
                    "clinical_trial_status": clean_str(row["clinical trial status"]),
                    "clinical_trial_start_date": clean_date(row["clinical trial start date"]),
                    "clinical_trial_completion_date": clean_date(row["clinical trial completion date"]),
                    "clinical_trial_participants": clean_int(row["clinical trial participants"]),
                    "trial_country": clean_str(row["clinical trial address"]),
                    "trial_institution": clean_str(row["clinical trial institution"]),
                    "trial_department": clean_str(row["clinical trial address.1"]),
                    "researcher_name": researcher_name
                }.items():
                    if trials[trial_title].get(key) is None and new_value is not None:
                        trials[trial_title][key] = new_value

            studies.add((drug_name, trial_title))

            # clinical trial conditions are multivalued in ER
            condition_cols = [
                "clinical trial condition",
                "clinical trial condition.1",
                "clinical trial condition.2"
            ]
            for cond in unique_non_empty([row[c] for c in condition_cols]):
                trial_conditions.add((trial_title, cond))

    # -----------------------------------------
    # INSERT INTO MYSQL
    # -----------------------------------------
    conn = None
    cursor = None

    try:
        conn = mysql.connector.connect(**DB_CONFIG)
        cursor = conn.cursor()

        cursor.execute("SET FOREIGN_KEY_CHECKS = 0")

        # RESEARCHER
        for researcher_name in sorted(researchers):
            cursor.execute(
                """
                INSERT IGNORE INTO RESEARCHER (researcher_name)
                VALUES (%s)
                """,
                (researcher_name,)
            )

        # DRUG
        for drug_name, drug_category in sorted(drugs.items()):
            cursor.execute(
                """
                INSERT IGNORE INTO DRUG (drug_name, drug_category)
                VALUES (%s, %s)
                """,
                (drug_name, drug_category)
            )

        # DISEASE
        for disease_name, disease_category in sorted(diseases.items()):
            cursor.execute(
                """
                INSERT IGNORE INTO DISEASE (disease_name, disease_category)
                VALUES (%s, %s)
                """,
                (disease_name, disease_category)
            )

        # SIDE_EFFECT
        for side_effect_name in sorted(side_effects):
            cursor.execute(
                """
                INSERT IGNORE INTO SIDE_EFFECT (side_effect_name)
                VALUES (%s)
                """,
                (side_effect_name,)
            )

        # CLINICAL_TRIAL
        for title, t in sorted(trials.items()):
            if not t["researcher_name"]:
                # skip trial if the 1:1 researcher is missing
                continue

            cursor.execute(
                """
                INSERT IGNORE INTO CLINICAL_TRIAL (
                    clinical_trial_title,
                    clinical_trial_status,
                    clinical_trial_start_date,
                    clinical_trial_completion_date,
                    clinical_trial_participants,
                    trial_country,
                    trial_institution,
                    trial_department,
                    researcher_name
                )
                VALUES (%s, %s, %s, %s, %s, %s, %s, %s, %s)
                """,
                (
                    title,
                    t["clinical_trial_status"],
                    t["clinical_trial_start_date"],
                    t["clinical_trial_completion_date"],
                    t["clinical_trial_participants"],
                    t["trial_country"],
                    t["trial_institution"],
                    t["trial_department"],
                    t["researcher_name"]
                )
            )

        # PRODUCT
        for product_name, p in sorted(products.items()):
            if not p["drug_name"]:
                continue

            cursor.execute(
                """
                INSERT IGNORE INTO PRODUCT (
                    product_name,
                    company_name,
                    drug_name
                )
                VALUES (%s, %s, %s)
                """,
                (
                    product_name,
                    p["company_name"],
                    p["drug_name"]
                )
            )

        # HAS_SIDE_EFFECT
        for drug_name, side_effect_name in sorted(has_side_effect):
            cursor.execute(
                """
                INSERT IGNORE INTO HAS_SIDE_EFFECT (drug_name, side_effect_name)
                VALUES (%s, %s)
                """,
                (drug_name, side_effect_name)
            )

        # TREATS
        for drug_name, disease_name in sorted(treats):
            cursor.execute(
                """
                INSERT IGNORE INTO TREATS (drug_name, disease_name)
                VALUES (%s, %s)
                """,
                (drug_name, disease_name)
            )

        # STUDIES
        valid_trials = {k for k, v in trials.items() if v["researcher_name"]}
        for drug_name, trial_title in sorted(studies):
            if trial_title in valid_trials:
                cursor.execute(
                    """
                    INSERT IGNORE INTO STUDIES (drug_name, clinical_trial_title)
                    VALUES (%s, %s)
                    """,
                    (drug_name, trial_title)
                )

        # DRUG_INTERACTION
        for drug_a, drug_b in sorted(drug_interactions):
            cursor.execute(
                """
                INSERT IGNORE INTO DRUG_INTERACTION (drug_name, interacts_with_drug_name)
                VALUES (%s, %s)
                """,
                (drug_a, drug_b)
            )
            cursor.execute(
                """
                INSERT IGNORE INTO DRUG_INTERACTION (drug_name, interacts_with_drug_name)
                VALUES (%s, %s)
                """,
                (drug_b, drug_a)
            )

        # CLINICAL_TRIAL_CONDITION
        for trial_title, condition_name in sorted(trial_conditions):
            if trial_title in valid_trials:
                cursor.execute(
                    """
                    INSERT IGNORE INTO CLINICAL_TRIAL_CONDITION (clinical_trial_title, condition_name)
                    VALUES (%s, %s)
                    """,
                    (trial_title, condition_name)
                )

        cursor.execute("SET FOREIGN_KEY_CHECKS = 1")
        conn.commit()
        print("Task 2 data imported successfully into PHARMA_DB_TASK2.")

    except Error as e:
        print("MySQL Error:", e)
        if conn:
            conn.rollback()

    finally:
        if cursor is not None:
            cursor.close()
        if conn is not None and conn.is_connected():
            conn.close()

if __name__ == "__main__":
    main()