select e.last_name, e.employee_id, d.last_name, d.employee_id
from employees e join employees d
on (e.manager_id = d.employee_id);