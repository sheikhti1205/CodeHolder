select o.museum_id, count(l.object_id)
from Museum o join Museum_Object l
where 