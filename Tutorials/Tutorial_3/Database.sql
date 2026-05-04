DROP DATABASE IF EXISTS demo;
CREATE DATABASE demo CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci;
USE demo;

DROP TABLE IF EXISTS museum;
CREATE TABLE museum (
    Mus_Name VARCHAR(100) NOT NULL,
    Mus_ID VARCHAR(50) NULL,
    Obj_Name VARCHAR(255) NOT NULL,
    Obj_ID VARCHAR(50) NOT NULL,
    Obj_Len DECIMAL(10, 2) NULL,
    Obj_Wid DECIMAL(10, 2) NULL,
    Obj_height DECIMAL(10, 2) NULL,
    Obj_Mat TEXT NULL,
    Obj_GeoRef VARCHAR(255) NULL,
    Obj_country VARCHAR(255) NULL,
    Per_Name VARCHAR(255) NULL,
    Acq_year SMALLINT NULL,
    Acq_month TINYINT NULL,
    Acq_date TINYINT NULL,
    PRIMARY KEY (Obj_ID)
);

INSERT INTO museum (
    Mus_Name,
    Mus_ID,
    Obj_Name,
    Obj_ID,
    Obj_Len,
    Obj_Wid,
    Obj_height,
    Obj_Mat,
    Obj_GeoRef,
    Obj_country,
    Per_Name,
    Acq_year,
    Acq_month,
    Acq_date
) VALUES
    ('Museum 1', 'RV 1184 421', 'boog', 'RV-1184-421', NULL, NULL, NULL, 'hout; pees', 'Brazilians', 'boog', 'Amelia burggravin van Cavalcabo', 1898, 8, 1),
    ('Museum 1', 'RV 1184 422', 'trofee', 'RV-1184-422', 10, 7, 5.5, 'huid; hout; katoen; mensenhaar; veren', 'Jivaro', 'OORLOGSTROFEE VAN EEN GESCHROMPELDE HOOFD', 'Amelia burggravin van Cavalcabo', 1898, 8, 1),
    ('Museum 1', 'RV 1194 1', 'kan', 'RV-1194-1', NULL, NULL, NULL, 'aardewerk', 'Antilliaans', 'kan', 'Nationale Tentoonstelling van vrouwenarbeid', 1898, 9, 1),
    ('Museum 1', 'RV 1194 2', 'kookkruik-stop', 'RV-1194-2', NULL, NULL, NULL, 'aardewerk', 'Antilliaans', 'kookkruik stop', 'Nationale Tentoonstelling van vrouwenarbeid', 1898, 9, 1),
    ('Museum 1', 'RV 1194 3', 'strottenhoofd', 'RV-1194-3', NULL, NULL, NULL, 'dierlijk materiaal', 'Surinams', 'strottenhoofd van aap', 'Nationale Tentoonstelling van vrouwenarbeid', 1898, 9, 1),
    ('Museum 1', 'RV 1194 4', 'beeld / vogel', 'RV-1194-4', 9.3, 11.3, NULL, 'aardewerk', 'Karaiben', 'VOGELTJE', 'Nationale Tentoonstelling van vrouwenarbeid', 1898, 9, 1),
    ('Museum 1', 'RV 1194 5', 'lendendoek', 'RV-1194-5', 95, 69, NULL, 'katoen', 'Saramaka', 'DOEK OF PANDJE VOOR MANNEN', 'Nationale Tentoonstelling van vrouwenarbeid', 1898, 9, 1),
    ('Museum 1', 'RV 1194 6', 'doek', 'RV-1194-6', NULL, NULL, NULL, 'textiel', 'Marrons', 'doek', 'Nationale Tentoonstelling van vrouwenarbeid', 1898, 9, 1),
    ('Museum 1', 'RV 1200 18', 'knots', 'RV-1200-18', 69.7, 8.3, 2.2, 'hout', 'Guyanans (primitive tribes)', 'knots', 'Vondelhuis der Notarissen', 1898, 11, 1),
    ('Museum 2', NULL, 'Steinbeilklinge', 'IV Ca 4577', 9.5, 4, 2.5, 'Stein', 'Guatemala; St. Lucas', NULL, 'Wilhelm Schleiden', 1877, NULL, NULL),
    ('Museum 2', NULL, 'Steinfigur', 'IV Ca 4578', 14, 5.2, 6, 'Stein', 'Guatemala; St. Lucas', NULL, 'Wilhelm Schleiden', 1877, NULL, NULL),
    ('Museum 2', NULL, 'Steinaufsatz', 'IV Ca 4579', 25.1, 22.6, 18, 'Stein', 'Guatemala; Antigua', NULL, 'Geppy (?) Herrera', 1877, NULL, NULL),
    ('Museum 2', NULL, 'Steinkopf', 'IV Ca 4580', 17, 13, 9.5, 'Stein', 'Guatemala; Neu Guatemala', NULL, 'Hermann Albert Schumacher', 1877, NULL, NULL),
    ('Museum 2', NULL, 'Reibstein (Fragment)', 'IV Ca 4581', 12, 6, 5.7, 'Stein', 'Guatemala; Utatlan (Santa Cruz del Quiche)', NULL, 'Adolf Bastian', 1878, NULL, NULL);
