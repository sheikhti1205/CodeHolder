select employee_id, concat(first_name, last_name) NAME, length(last_name), instr(last_name, 'a') "Contains 'a'?"
from employees
where substr(last_name, -1, 1) = 'n';