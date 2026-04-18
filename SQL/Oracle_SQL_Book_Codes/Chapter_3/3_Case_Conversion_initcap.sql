select employee_id, last_name, department_id, initcap('something')
from employees
where initcap(last_name) = 'Higgins';

-- Basically initcap converts the first letter to uppercase letter