select count(*), count(distinct(commission_pct))
from employees
where department_id = 80;