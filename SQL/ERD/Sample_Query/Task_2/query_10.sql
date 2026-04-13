USE PHARMA_DB_TASK2;

SELECT DISTINCT c.researcher_name
FROM CLINICAL_TRIAL c
JOIN STUDIES s
  ON c.clinical_trial_title = s.clinical_trial_title
WHERE s.drug_name IN (
    SELECT t.drug_name
    FROM TREATS t
    JOIN DISEASE d
      ON t.disease_name = d.disease_name
    WHERE LOWER(d.disease_category) IN ('respiratory', 'cardiovascular')
    GROUP BY t.drug_name
    HAVING COUNT(DISTINCT LOWER(d.disease_category)) = 2
)
ORDER BY c.researcher_name;