select e.last_name, e.employee_id, m.last_name, m.employee_id
from employees e left outer join employees m 
on (e.manager_id = m.employee_id)
order by e.employee_id;