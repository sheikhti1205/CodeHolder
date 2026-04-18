select last_name, salary, commission_pct
from employees
where commission_pct is not NULL
order by salary desc, commission_pct desc;

-- we can use order by 2 desc, 3 desc; which is the same if you understand...
