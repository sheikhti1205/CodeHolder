select last_name, job_id
from employees
where job_id not in ('SA_MAN', 'ST_MAN');

-- escape only works with like operator -_-