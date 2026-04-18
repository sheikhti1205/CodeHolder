select employee_id, last_name, salary, manager_id
from employees
where manager_id IN (100, 101, 201);

-- Another:

select employee_id, last_name, salary
from EMPLOYEES
where last_name in ('Higgins', 'Jacobs');