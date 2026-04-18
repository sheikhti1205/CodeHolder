select job_id, max(salary), min(salary), (max(salary) - min(salary)) Difference
from employees
where job_id = '&var'
group by job_id;