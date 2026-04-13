USE PHARMA_DB_TASK2;

SELECT DISTINCT drug_name
FROM DRUG_INTERACTION
WHERE LOWER(interacts_with_drug_name) = 'butabarbital'
ORDER BY drug_name;