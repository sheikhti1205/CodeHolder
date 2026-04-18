select department_id, round(avg(salary))
from employees
having avg(salary) >= 8000
group by department_id;