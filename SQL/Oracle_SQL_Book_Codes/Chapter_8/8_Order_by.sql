SELECT employee_id, job_id, salary
from employees
UNION
SELECT employee_id, job_id, 0
from job_history
order by 2;