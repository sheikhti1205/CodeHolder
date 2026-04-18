select job_id, count(*)
from EMPLOYEES
where job_id = '&var'
group by job_id;