USE PHARMA_DB_TASK2;

SELECT drug_name
FROM HAS_SIDE_EFFECT
WHERE LOWER(side_effect_name) IN ('cough', 'headache')
GROUP BY drug_name
HAVING COUNT(DISTINCT LOWER(side_effect_name)) = 2
ORDER BY drug_name;