SELECT last_name, job_id, department_id, hire_date
FROM employees
ORDER BY hire_date;

-- order by is usually in ascending order

-- using 'desc' after hire_date we can tell it to show descendingly
-- 'asc means ascending

SELECT last_name, department_id, salary
FROM employees
ORDER BY department_id, salary DESC;