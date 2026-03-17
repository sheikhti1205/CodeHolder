select last_name, trunc((sysdate - hire_date) / 7, 0) Tenure
from employees
where department_id = 90
order by Tenure;