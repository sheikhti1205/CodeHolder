select round(avg(salary)), max(salary), min(salary), sum(salary)
from employees
where job_id like '%REP%';