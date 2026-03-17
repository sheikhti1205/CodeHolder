select e.last_name, e.employee_id, e.department_id, d.department_id, d.location_id
from employees e join departments d
on (e.department_id = d.department_id)
-- where e.manager_id = 149;
and e.manager_id = 149;

-- Here both AND and WHERE conditioning works