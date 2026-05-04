USE demo;

SELECT
    TRIM(SUBSTRING_INDEX(Obj_GeoRef, ';', 1)) AS Country_Origin,
    COUNT(*) AS total_objects
FROM museum
WHERE Obj_GeoRef IS NOT NULL
GROUP BY TRIM(SUBSTRING_INDEX(Obj_GeoRef, ';', 1))
ORDER BY total_objects DESC, Country_Origin ASC;
