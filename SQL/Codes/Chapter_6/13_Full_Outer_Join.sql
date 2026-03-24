select e.last_name, d.department_id, d.department_name
from employees e full outer join departments d
on (e.department_id = d.department_id);