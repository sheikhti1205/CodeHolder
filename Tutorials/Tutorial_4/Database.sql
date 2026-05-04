DROP DATABASE IF EXISTS medical_db_task3;
CREATE DATABASE medical_db_task3;
USE medical_db_task3;

CREATE TABLE drug (
    drug_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (drug_name)
);

CREATE TABLE drug_category (
    category_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (category_name)
);

CREATE TABLE drug_has_category (
    drug_name VARCHAR(120) NOT NULL,
    category_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (drug_name, category_name),
    FOREIGN KEY (drug_name) REFERENCES drug(drug_name),
    FOREIGN KEY (category_name) REFERENCES drug_category(category_name)
);

CREATE TABLE disease_category (
    category_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (category_name)
);

CREATE TABLE disease (
    disease_name VARCHAR(200) NOT NULL,
    category_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (disease_name),
    FOREIGN KEY (category_name) REFERENCES disease_category(category_name)
);

CREATE TABLE side_effect (
    side_effect_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (side_effect_name)
);

CREATE TABLE drug_treats (
    drug_name VARCHAR(120) NOT NULL,
    disease_name VARCHAR(200) NOT NULL,
    PRIMARY KEY (drug_name, disease_name),
    FOREIGN KEY (drug_name) REFERENCES drug(drug_name),
    FOREIGN KEY (disease_name) REFERENCES disease(disease_name)
);

CREATE TABLE drug_has_side_effect (
    drug_name VARCHAR(120) NOT NULL,
    side_effect_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (drug_name, side_effect_name),
    FOREIGN KEY (drug_name) REFERENCES drug(drug_name),
    FOREIGN KEY (side_effect_name) REFERENCES side_effect(side_effect_name)
);

CREATE TABLE drug_interaction (
    drug_name VARCHAR(120) NOT NULL,
    interacting_drug_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (drug_name, interacting_drug_name),
    FOREIGN KEY (drug_name) REFERENCES drug(drug_name),
    FOREIGN KEY (interacting_drug_name) REFERENCES drug(drug_name),
    CHECK (drug_name < interacting_drug_name)
);

CREATE TABLE company (
    company_name VARCHAR(160) NOT NULL,
    PRIMARY KEY (company_name)
);

CREATE TABLE product (
    product_name VARCHAR(160) NOT NULL,
    company_name VARCHAR(160) NOT NULL,
    drug_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (product_name, company_name),
    FOREIGN KEY (company_name) REFERENCES company(company_name),
    FOREIGN KEY (drug_name) REFERENCES drug(drug_name)
);

CREATE TABLE institution (
    institution_name VARCHAR(200) NOT NULL,
    country VARCHAR(100) NOT NULL,
    facility_address VARCHAR(255),
    PRIMARY KEY (institution_name, country)
);

CREATE TABLE researcher (
    researcher_name VARCHAR(160) NOT NULL,
    institution_name VARCHAR(200) NOT NULL,
    country VARCHAR(100) NOT NULL,
    PRIMARY KEY (researcher_name, institution_name, country),
    FOREIGN KEY (institution_name, country)
        REFERENCES institution(institution_name, country)
);

CREATE TABLE clinical_trial (
    trial_title VARCHAR(255) NOT NULL,
    start_date DATE,
    completion_date DATE,
    participants INT,
    status VARCHAR(80),
    institution_name VARCHAR(200) NOT NULL,
    country VARCHAR(100) NOT NULL,
    main_researcher_name VARCHAR(160) NOT NULL,
    PRIMARY KEY (trial_title),
    FOREIGN KEY (institution_name, country)
        REFERENCES institution(institution_name, country),
    FOREIGN KEY (main_researcher_name, institution_name, country)
        REFERENCES researcher(researcher_name, institution_name, country),
    CHECK (participants IS NULL OR participants >= 0)
);

CREATE TABLE clinical_trial_studies_drug (
    trial_title VARCHAR(255) NOT NULL,
    drug_name VARCHAR(120) NOT NULL,
    PRIMARY KEY (trial_title, drug_name),
    FOREIGN KEY (trial_title) REFERENCES clinical_trial(trial_title),
    FOREIGN KEY (drug_name) REFERENCES drug(drug_name)
);

CREATE TABLE condition_studied (
    condition_name VARCHAR(200) NOT NULL,
    PRIMARY KEY (condition_name)
);

CREATE TABLE clinical_trial_condition (
    trial_title VARCHAR(255) NOT NULL,
    condition_name VARCHAR(200) NOT NULL,
    PRIMARY KEY (trial_title, condition_name),
    FOREIGN KEY (trial_title) REFERENCES clinical_trial(trial_title),
    FOREIGN KEY (condition_name) REFERENCES condition_studied(condition_name)
);
