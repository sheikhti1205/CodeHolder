select e.last_name, e.department_id, d.department_name
from employees e right outer join departments d
on (e.department_id = d.department_id);