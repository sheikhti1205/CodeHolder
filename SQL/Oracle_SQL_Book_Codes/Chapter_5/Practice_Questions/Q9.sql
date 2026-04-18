select manager_id, min(salary)
from employees
where manager_id is not NULL
group by manager_id;