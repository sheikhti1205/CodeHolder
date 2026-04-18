select e.employee_id, l.city, d.department_name
from employees e
join departments d
using (department_id)
join locations l
using (location_id);