select employee_id, job_id
from employees
INTERSECT
select employee_id, job_id
from job_history;