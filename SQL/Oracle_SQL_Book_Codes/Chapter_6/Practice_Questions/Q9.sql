SELECT e.last_name AS Employee,
       e.hire_date AS "Emp Hire Date",
       m.last_name AS Manager,
       m.hire_date AS "Mgr Hire Date"
FROM employees e
JOIN employees m
ON e.manager_id = m.employee_id
WHERE e.hire_date < m.hire_date;