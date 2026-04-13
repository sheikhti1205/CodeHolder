# Medical Database Mini-Project Guide

This note is the short study guide for the two DBMS mini-project tasks.

It matches the files I prepared:

- `Latex/Medical_Database_Task1/task1_report.tex`
- `Latex/Medical_Database_Task2/task2_report.tex`
- `SQL/Medical_Database/task1_preliminary_schema.sql`
- `SQL/Medical_Database/task2_natural_key_schema.sql`

## 1. What the assignment is really asking

Task 1 is asking for a **reasonable first database design**.

You need to show:

- what information the database should store
- what tables you would create
- optional SQL to create those tables

Task 2 is asking for a **better, more formal redesign** using course ideas.

You need to show:

- relevant data items
- an ER design with cardinalities
- a relational model with PK, CK, and FK
- a reflection comparing Task 2 with Task 1

## 2. The biggest idea: the Excel sheet is not a table

The sample workbook looks like data, but it is **not** a proper relational table.

Why?

- one row contains several side effects
- one row contains several interacting drugs
- one row contains several clinical trial conditions
- the same trial information repeats across many rows
- the same drug appears in many rows because it treats many diseases

That means the spreadsheet is a **denormalized source**, not the final schema.

## 3. How to think about the design

When you look at messy sample data, ask these questions:

1. What are the main things that exist on their own?
2. Which things repeat across rows?
3. Which relationships are one-to-many?
4. Which relationships are many-to-many?
5. Which attributes are really repeating groups and should become separate tables?

For this project, the main things are:

- Drug
- DrugCategory
- Disease
- DiseaseCategory
- SideEffect
- Product
- Company
- ClinicalTrial
- Institution
- Researcher
- Condition

## 4. Why the bridge tables are necessary

Several relationships are many-to-many.

Examples:

- one drug can treat many diseases
- one disease can be treated by many drugs
- one drug can have many side effects
- one side effect can belong to many drugs
- one drug can be studied in many trials
- one trial can study many drugs

In a relational database, many-to-many relationships become bridge tables.

Examples:

- `DrugTreats(drug_name, disease_name)`
- `DrugHasSideEffect(drug_name, side_effect_name)`
- `ClinicalTrialStudiesDrug(trial_title, drug_name)`

## 5. A key design choice from the sample data

The sample data shows that **a drug can belong to multiple drug categories**.

Examples from the workbook:

- `abciximab` appears under more than one category
- `etanercept` appears under more than one category

So in Task 2, `Drug` and `DrugCategory` should not be modeled as one-to-many.

A better design is:

- `Drug(drug_name)`
- `DrugCategory(category_name)`
- `DrugHasCategory(drug_name, category_name)`

This is a strong point to mention if your teacher asks why you changed the design.

## 6. Task 1 vs Task 2 in simple words

Task 1:

- focuses on a practical first design
- can use surrogate IDs
- mainly proves that you understand how to break the spreadsheet into tables

Task 2:

- is more formal
- should use course notation
- should justify cardinalities
- should prefer natural keys where reasonable
- should explain design choices

So the reports should not look identical.

## 7. Why Task 2 uses more natural keys

In Task 1, using integer IDs everywhere is acceptable for a first draft.

In Task 2, the assignment explicitly says not to blindly add ID attributes.

That means you should look for native identifiers such as:

- `drug_name`
- `disease_name`
- `category_name`
- `company_name`
- `trial_title`

For some entities, a composite natural key is better:

- `Product(product_name, company_name)`
- `Institution(institution_name, country)`
- `Researcher(researcher_name, institution_name, country)`

This is a good example of stronger conceptual design.

## 8. Why `Condition` was kept separate from `Disease`

This is one of the most defensible design choices in Task 2.

The clinical trial conditions in the workbook do not always line up cleanly with the disease names
from the treatment rows.

So if you force them into the same entity too early, you may create false matches.

That is why Task 2 uses:

- `Disease` for diseases treated by drugs
- `Condition` for conditions explicitly listed in clinical trials

If your teacher prefers combining them, you can still explain that you separated them to avoid
incorrect assumptions from incomplete sample data.

## 9. How to explain the self-relationship

Drug interaction is a classic self-relationship.

Meaning:

- a drug interacts with another drug
- both ends are the same entity type: `Drug`

That is why the relational table looks like:

```sql
DrugInteraction(drug_name, interacting_drug_name)
```

A good extra point:

- store each pair once using a rule like `drug_name < interacting_drug_name`

That avoids duplicate rows like:

- `(hydrocortisone, butabarbital)`
- `(butabarbital, hydrocortisone)`

## 10. How the sample queries map to the schema

Here is the logic behind the sample queries.

### Query a
Find the number of drugs that have nausea as a side effect.

Use:

- `DrugHasSideEffect`
- `SideEffect`

### Query b
Find the drugs that interact with butabarbital.

Use:

- `DrugInteraction`
- `Drug`

### Query c
Find the drugs with side effects cough and headache.

Use:

- `DrugHasSideEffect`
- group by drug
- `HAVING COUNT(DISTINCT side_effect_name) = 2`

### Query d
Find the drugs that can be used to treat endocrine diseases.

Use:

- `DrugTreats`
- `Disease`
- `DiseaseCategory`

### Query e
Find the most common treatment for immunological diseases that have not been used for hematological diseases.

Use:

- `DrugTreats`
- `Disease`
- filter immunological diseases
- exclude drugs that also treat hematological diseases
- group by drug

### Query f
Find the diseases that can be treated with hydrocortisone but not with etanercept.

Use:

- set difference between two filtered `DrugTreats` results

### Query g
Find the top-10 side effects that drugs used to treat asthma-related diseases have.

Use:

- `DrugTreats`
- `Disease`
- `DrugHasSideEffect`
- `SideEffect`
- then group by side effect and order by frequency

### Query h
Find the drugs that have been studied in more than three clinical trials with more than 30 participants.

Use:

- `ClinicalTrial`
- `ClinicalTrialStudiesDrug`
- filter `participants > 30`
- group by drug

### Query i
Find the largest number of clinical trials and the drugs they have studied that have been active in the same period of time.

Use:

- `ClinicalTrial`
- overlap logic on start and completion dates
- `ClinicalTrialStudiesDrug`

### Query j and k
Find the main researchers for trials studying drugs that can treat both respiratory and cardiovascular diseases.

Use:

- `Researcher`
- `ClinicalTrial`
- `ClinicalTrialStudiesDrug`
- `DrugTreats`
- `Disease`
- `DiseaseCategory`

### Query l
Find the categories of drugs that have been only studied in clinical trials based in United States.

Use:

- `DrugHasCategory`
- `ClinicalTrialStudiesDrug`
- `ClinicalTrial`
- `Institution`

## 11. A few SQL skeletons you can learn from

### Drugs with both cough and headache

```sql
SELECT dhs.drug_name
FROM DrugHasSideEffect AS dhs
JOIN SideEffect AS se
  ON se.side_effect_name = dhs.side_effect_name
WHERE se.side_effect_name IN ('cough', 'headache')
GROUP BY dhs.drug_name
HAVING COUNT(DISTINCT se.side_effect_name) = 2;
```

### Drugs that treat endocrine diseases

```sql
SELECT DISTINCT dt.drug_name
FROM DrugTreats AS dt
JOIN Disease AS d
  ON d.disease_name = dt.disease_name
WHERE d.category_name = 'Endocrine';
```

### Diseases treated by hydrocortisone but not etanercept

```sql
SELECT disease_name
FROM DrugTreats
WHERE drug_name = 'hydrocortisone'
EXCEPT
SELECT disease_name
FROM DrugTreats
WHERE drug_name = 'etanercept';
```

## 12. How to defend your report in class or viva

If someone asks why your design looks the way it does, these are good answers:

- The spreadsheet contains repeating groups, so it cannot be stored as one relation.
- Many sample queries are many-to-many by nature, so bridge tables are required.
- Drug categories were made many-to-many because the sample data actually shows that case.
- Clinical trial information was separated because trials repeat across many rows.
- Task 2 uses natural keys because the assignment explicitly asks for thoughtful key selection.

## 13. Final takeaway

The real lesson of this assignment is not just drawing boxes and tables.

The lesson is:

- separate entities from repeating values
- model many-to-many relationships correctly
- choose keys carefully
- explain assumptions clearly

If you can explain those four things, you understand the assignment well.
