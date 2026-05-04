USE demo;

SELECT Per_Name AS Acquirer, COUNT(*) AS total_items
FROM museum
WHERE Per_Name IS NOT NULL
GROUP BY Per_Name
ORDER BY total_items DESC, Acquirer ASC;
