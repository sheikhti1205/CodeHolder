USE PHARMA_DB_TASK2;

SELECT s.drug_name
FROM STUDIES s
JOIN CLINICAL_TRIAL c
  ON s.clinical_trial_title = c.clinical_trial_title
WHERE c.clinical_trial_participants > 30
GROUP BY s.drug_name
HAVING COUNT(DISTINCT s.clinical_trial_title) > 3
ORDER BY s.drug_name;