select employee_id, last_name, job_id, salary
from employees
where salary >= 10000
and job_id like '%MAN%';

-- replace and with or you'll get more 