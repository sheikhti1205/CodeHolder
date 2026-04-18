select department_id, round(avg(salary))
from employees
group by department_id;
-- or --
select round(avg(salary)), max(salary)
from EMPLOYEES
group by department_id
order by max(salary) desc;