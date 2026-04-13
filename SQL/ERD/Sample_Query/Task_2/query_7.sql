USE PHARMA_DB_TASK2;

SELECT h.side_effect_name, COUNT(*) AS frequency
FROM HAS_SIDE_EFFECT h
JOIN TREATS t
  ON h.drug_name = t.drug_name
JOIN DISEASE d
  ON t.disease_name = d.disease_name
WHERE LOWER(d.disease_name) LIKE '%asthma%'
GROUP BY h.side_effect_name
ORDER BY frequency DESC, h.side_effect_name
LIMIT 10;