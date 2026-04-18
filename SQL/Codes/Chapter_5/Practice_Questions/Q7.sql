select job_id, count(manager_id) "Number of Managers"
from employees
group by job_id;