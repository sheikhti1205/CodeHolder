-- =========================================
-- TASK 2 SQL
-- ER-DIAGRAM-BASED VERSION
-- =========================================

DROP DATABASE IF EXISTS PHARMA_DB_TASK2;
CREATE DATABASE IF NOT EXISTS PHARMA_DB_TASK2;
USE PHARMA_DB_TASK2;

-- =========================================
-- ENTITY TABLES
-- =========================================

CREATE TABLE IF NOT EXISTS RESEARCHER (
    researcher_name VARCHAR(255) PRIMARY KEY
);

CREATE TABLE IF NOT EXISTS DRUG (
    drug_name      VARCHAR(255) PRIMARY KEY,
    drug_category  VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS DISEASE (
    disease_name      VARCHAR(255) PRIMARY KEY,
    disease_category  VARCHAR(255)
);

CREATE TABLE IF NOT EXISTS SIDE_EFFECT (
    side_effect_name VARCHAR(255) PRIMARY KEY
);

CREATE TABLE IF NOT EXISTS PRODUCT (
    product_name   VARCHAR(255) PRIMARY KEY,
    company_name   VARCHAR(255) NOT NULL,
    drug_name      VARCHAR(255) NOT NULL,
    CONSTRAINT fk_product_drug
        FOREIGN KEY (drug_name) REFERENCES DRUG(drug_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

CREATE TABLE IF NOT EXISTS CLINICAL_TRIAL (
    clinical_trial_title            VARCHAR(500) PRIMARY KEY,
    clinical_trial_status           VARCHAR(100),
    clinical_trial_start_date       DATE,
    clinical_trial_completion_date  DATE,
    clinical_trial_participants     INT,
    trial_country                   VARCHAR(255),
    trial_institution               VARCHAR(255),
    trial_department                VARCHAR(255),
    researcher_name                 VARCHAR(255) NOT NULL UNIQUE,
    CONSTRAINT fk_trial_researcher
        FOREIGN KEY (researcher_name) REFERENCES RESEARCHER(researcher_name)
        ON DELETE RESTRICT
        ON UPDATE CASCADE
);

-- =========================================
-- MULTIVALUED ATTRIBUTE TABLES
-- =========================================

-- DRUG has multivalued attribute: interacts with
CREATE TABLE IF NOT EXISTS DRUG_INTERACTION (
    drug_name                 VARCHAR(255) NOT NULL,
    interacts_with_drug_name  VARCHAR(255) NOT NULL,
    PRIMARY KEY (drug_name, interacts_with_drug_name),
    CONSTRAINT fk_interaction_drug_1
        FOREIGN KEY (drug_name) REFERENCES DRUG(drug_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_interaction_drug_2
        FOREIGN KEY (interacts_with_drug_name) REFERENCES DRUG(drug_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- CLINICAL_TRIAL has multivalued attribute: clinical trial condition
CREATE TABLE IF NOT EXISTS CLINICAL_TRIAL_CONDITION (
    clinical_trial_title   VARCHAR(500) NOT NULL,
    condition_name         VARCHAR(255) NOT NULL,
    PRIMARY KEY (clinical_trial_title, condition_name),
    CONSTRAINT fk_trial_condition_trial
        FOREIGN KEY (clinical_trial_title) REFERENCES CLINICAL_TRIAL(clinical_trial_title)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- =========================================
-- RELATIONSHIP TABLES
-- =========================================

-- STUDIES : DRUG M:N CLINICAL_TRIAL
CREATE TABLE IF NOT EXISTS STUDIES (
    drug_name               VARCHAR(255) NOT NULL,
    clinical_trial_title    VARCHAR(500) NOT NULL,
    PRIMARY KEY (drug_name, clinical_trial_title),
    CONSTRAINT fk_studies_drug
        FOREIGN KEY (drug_name) REFERENCES DRUG(drug_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_studies_trial
        FOREIGN KEY (clinical_trial_title) REFERENCES CLINICAL_TRIAL(clinical_trial_title)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- TREATS : DRUG M:N DISEASE
CREATE TABLE IF NOT EXISTS TREATS (
    drug_name      VARCHAR(255) NOT NULL,
    disease_name   VARCHAR(255) NOT NULL,
    PRIMARY KEY (drug_name, disease_name),
    CONSTRAINT fk_treats_drug
        FOREIGN KEY (drug_name) REFERENCES DRUG(drug_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_treats_disease
        FOREIGN KEY (disease_name) REFERENCES DISEASE(disease_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- HAS : DRUG M:N SIDE_EFFECT
CREATE TABLE IF NOT EXISTS HAS_SIDE_EFFECT (
    drug_name          VARCHAR(255) NOT NULL,
    side_effect_name   VARCHAR(255) NOT NULL,
    PRIMARY KEY (drug_name, side_effect_name),
    CONSTRAINT fk_has_drug
        FOREIGN KEY (drug_name) REFERENCES DRUG(drug_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE,
    CONSTRAINT fk_has_side_effect
        FOREIGN KEY (side_effect_name) REFERENCES SIDE_EFFECT(side_effect_name)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);

-- =========================================
-- OPTIONAL INDEXES
-- =========================================

CREATE INDEX idx_drug_category ON DRUG(drug_category);
CREATE INDEX idx_disease_category ON DISEASE(disease_category);
CREATE INDEX idx_product_company ON PRODUCT(company_name);
CREATE INDEX idx_trial_status ON CLINICAL_TRIAL(clinical_trial_status);