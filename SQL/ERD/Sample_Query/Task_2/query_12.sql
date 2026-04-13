USE PHARMA_DB_TASK2;

SELECT DISTINCT d.drug_category
FROM DRUG d
WHERE d.drug_name IN (
    SELECT s.drug_name
    FROM STUDIES s
    JOIN CLINICAL_TRIAL c
      ON s.clinical_trial_title = c.clinical_trial_title
    GROUP BY s.drug_name
    HAVING SUM(CASE WHEN c.trial_country <> 'United States' THEN 1 ELSE 0 END) = 0
)
ORDER BY d.drug_category;