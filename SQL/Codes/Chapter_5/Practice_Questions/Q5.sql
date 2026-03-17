select job_id, max(salary), min(salary), sum(salary), round(avg(salary))
from EMPLOYEES
group by job_id;