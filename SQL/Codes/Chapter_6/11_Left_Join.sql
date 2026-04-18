select e.last_name, e.department_id, d.department_id
from employees e left outer join departments d 
on (e.department_id = d.department_id);