select last_name, salary, mod(salary, 500)
from employees
where job_id = 'SA_REP';