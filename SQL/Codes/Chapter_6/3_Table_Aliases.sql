select l.city, d.department_name
from locations l join departments d
using (location_id)
where location_id = 1400;