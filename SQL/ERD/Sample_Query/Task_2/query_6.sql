USE PHARMA_DB_TASK2;

SELECT disease_name
FROM TREATS
WHERE drug_name = 'hydrocortisone'
  AND disease_name NOT IN (
      SELECT disease_name
      FROM TREATS
      WHERE drug_name = 'etanercept'
  )
ORDER BY disease_name;