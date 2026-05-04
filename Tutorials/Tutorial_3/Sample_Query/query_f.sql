USE demo;

SELECT Obj_Name, COUNT(*) AS total_count
FROM museum
WHERE Obj_Name IS NOT NULL
GROUP BY Obj_Name
ORDER BY total_count DESC, Obj_Name ASC;
