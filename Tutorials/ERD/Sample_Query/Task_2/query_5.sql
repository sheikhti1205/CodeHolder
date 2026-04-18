USE PHARMA_DB_TASK2;

SELECT t.drug_name, COUNT(*) AS usage_count
FROM TREATS t
JOIN DISEASE d
  ON t.disease_name = d.disease_name
WHERE LOWER(d.disease_category) = 'immunological'
  AND t.drug_name NOT IN (
      SELECT t2.drug_name
      FROM TREATS t2
      JOIN DISEASE d2
        ON t2.disease_name = d2.disease_name
      WHERE LOWER(d2.disease_category) = 'hematological'
  )
GROUP BY t.drug_name
ORDER BY usage_count DESC, t.drug_name;