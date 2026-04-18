USE demo;

SELECT Obj_Name, Obj_ID, Obj_Len, Obj_GeoRef
FROM museum
WHERE Obj_Len IS NOT NULL
ORDER BY Obj_Len DESC, Obj_ID ASC;
