select last_name, salary, department_id
from employees
where salary in (select min(salary)
                 from employees
                 group by department_id);