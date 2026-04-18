select employee_id, last_name, manager_id
from employees
where manager_id is NULL;