USE demo;

SELECT Mus_Name, COUNT(*) AS total_items
FROM museum
GROUP BY Mus_Name
ORDER BY total_items DESC, Mus_Name ASC
LIMIT 1;
