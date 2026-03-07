select employee_id, last_name, department_id
from employees
where last_name = 'higgins';

-- This will fail as there's no name with all lower characters
-- BUT this....

select employee_id, last_name, department_id
from employees
where lower(last_name) = 'higgins';
