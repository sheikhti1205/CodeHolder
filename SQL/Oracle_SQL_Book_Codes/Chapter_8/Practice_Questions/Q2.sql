SELECT country_id, country_name
from countries
minus
SELECT c.country_id, c.country_name
from countries c
join locations l
on c.country_id = l.country_id
join departments d
on l.location_id = d.location_id;