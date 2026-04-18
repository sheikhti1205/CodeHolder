select employee_id, concat(first_name, last_name) NAME, job_id, length(first_name), instr(last_name, 'a') "Contains 'a'?"
from employees
where substr(job_id, 4) = 'REP';