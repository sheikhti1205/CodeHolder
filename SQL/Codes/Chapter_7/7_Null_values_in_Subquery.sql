select emp.last_name
from employees emp
where emp.employee_id not in (select mgr.manager_id
                              from employees mgr);

select last_name from employees
where employee_id not in (select manager_id
                          from employees
                          where manager_id is not NULL);