CREATE TABLE drugs (
    drug_id INTEGER PRIMARY KEY,
    drug_name VARCHAR(120) NOT NULL UNIQUE,
    notes VARCHAR(255)
);

CREATE TABLE drug_categories (
    drug_category_id INTEGER PRIMARY KEY,
    category_name VARCHAR(120) NOT NULL UNIQUE
);

CREATE TABLE drug_category_assignments (
    drug_id INTEGER NOT NULL,
    drug_category_id INTEGER NOT NULL,
    PRIMARY KEY (drug_id, drug_category_id),
    FOREIGN KEY (drug_id) REFERENCES drugs(drug_id),
    FOREIGN KEY (drug_category_id) REFERENCES drug_categories(drug_category_id)
);

CREATE TABLE disease_categories (
    disease_category_id INTEGER PRIMARY KEY,
    category_name VARCHAR(120) NOT NULL UNIQUE
);

CREATE TABLE diseases (
    disease_id INTEGER PRIMARY KEY,
    disease_name VARCHAR(200) NOT NULL UNIQUE,
    disease_category_id INTEGER NOT NULL,
    FOREIGN KEY (disease_category_id) REFERENCES disease_categories(disease_category_id)
);

CREATE TABLE side_effects (
    side_effect_id INTEGER PRIMARY KEY,
    side_effect_name VARCHAR(120) NOT NULL UNIQUE
);

CREATE TABLE drug_treatments (
    drug_id INTEGER NOT NULL,
    disease_id INTEGER NOT NULL,
    PRIMARY KEY (drug_id, disease_id),
    FOREIGN KEY (drug_id) REFERENCES drugs(drug_id),
    FOREIGN KEY (disease_id) REFERENCES diseases(disease_id)
);

CREATE TABLE drug_side_effects (
    drug_id INTEGER NOT NULL,
    side_effect_id INTEGER NOT NULL,
    PRIMARY KEY (drug_id, side_effect_id),
    FOREIGN KEY (drug_id) REFERENCES drugs(drug_id),
    FOREIGN KEY (side_effect_id) REFERENCES side_effects(side_effect_id)
);

CREATE TABLE companies (
    company_id INTEGER PRIMARY KEY,
    company_name VARCHAR(160) NOT NULL UNIQUE
);

CREATE TABLE products (
    product_id INTEGER PRIMARY KEY,
    product_name VARCHAR(160) NOT NULL,
    drug_id INTEGER NOT NULL,
    company_id INTEGER NOT NULL,
    UNIQUE (product_name, company_id),
    FOREIGN KEY (drug_id) REFERENCES drugs(drug_id),
    FOREIGN KEY (company_id) REFERENCES companies(company_id)
);

CREATE TABLE drug_interactions (
    drug_id INTEGER NOT NULL,
    interacting_drug_id INTEGER NOT NULL,
    PRIMARY KEY (drug_id, interacting_drug_id),
    FOREIGN KEY (drug_id) REFERENCES drugs(drug_id),
    FOREIGN KEY (interacting_drug_id) REFERENCES drugs(drug_id),
    CHECK (drug_id <> interacting_drug_id)
);

CREATE TABLE institutions (
    institution_id INTEGER PRIMARY KEY,
    institution_name VARCHAR(200) NOT NULL UNIQUE,
    country VARCHAR(100) NOT NULL,
    facility_address VARCHAR(255)
);

CREATE TABLE researchers (
    researcher_id INTEGER PRIMARY KEY,
    researcher_name VARCHAR(160) NOT NULL,
    institution_id INTEGER NOT NULL,
    UNIQUE (researcher_name, institution_id),
    FOREIGN KEY (institution_id) REFERENCES institutions(institution_id)
);

CREATE TABLE clinical_trials (
    trial_id INTEGER PRIMARY KEY,
    trial_title VARCHAR(255) NOT NULL UNIQUE,
    start_date DATE,
    completion_date DATE,
    participants INTEGER,
    status VARCHAR(80),
    institution_id INTEGER,
    main_researcher_id INTEGER,
    FOREIGN KEY (institution_id) REFERENCES institutions(institution_id),
    FOREIGN KEY (main_researcher_id) REFERENCES researchers(researcher_id)
);

CREATE TABLE clinical_trial_drugs (
    trial_id INTEGER NOT NULL,
    drug_id INTEGER NOT NULL,
    PRIMARY KEY (trial_id, drug_id),
    FOREIGN KEY (trial_id) REFERENCES clinical_trials(trial_id),
    FOREIGN KEY (drug_id) REFERENCES drugs(drug_id)
);

CREATE TABLE trial_conditions (
    trial_condition_id INTEGER PRIMARY KEY,
    condition_name VARCHAR(200) NOT NULL UNIQUE
);

CREATE TABLE clinical_trial_conditions (
    trial_id INTEGER NOT NULL,
    trial_condition_id INTEGER NOT NULL,
    PRIMARY KEY (trial_id, trial_condition_id),
    FOREIGN KEY (trial_id) REFERENCES clinical_trials(trial_id),
    FOREIGN KEY (trial_condition_id) REFERENCES trial_conditions(trial_condition_id)
);
