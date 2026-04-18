SELECT employee_id
from employees
MINUS
SELECT employee_id
from job_history;