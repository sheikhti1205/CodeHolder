select e.department_id, e.last_name, d.last_name
from employees e join employees d
on (e.department_id = d.department_id)
where e.last_name = '&e_name';

-- exclude something i forgot :|

SELECT e.last_name AS Employee,
       e.department_id AS "Dept#",
       c.last_name AS Colleague
FROM employees e
JOIN employees c
ON e.department_id = c.department_id
WHERE e.last_name = '&employee_name'
AND e.employee_id <> c.employee_id;