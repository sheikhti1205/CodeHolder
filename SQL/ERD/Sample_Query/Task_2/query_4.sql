USE PHARMA_DB_TASK2;

SELECT DISTINCT t.drug_name
FROM TREATS t
JOIN DISEASE d
  ON t.disease_name = d.disease_name
WHERE LOWER(d.disease_category) = 'endocrine'
ORDER BY t.drug_name;