USE PHARMA_DB_TASK2;

SELECT COUNT(DISTINCT drug_name) AS number_of_drugs
FROM HAS_SIDE_EFFECT
WHERE side_effect_name = 'nausea';