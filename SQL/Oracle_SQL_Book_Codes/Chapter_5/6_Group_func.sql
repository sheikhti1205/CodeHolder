select department_id, job_id, sum(salary)
from employees
group by department_id, job_id
order by job_id;