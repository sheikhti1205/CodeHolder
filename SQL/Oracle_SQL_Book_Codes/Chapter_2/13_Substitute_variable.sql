SELECT employee_id, last_name, salary, department_id
FROM employees
WHERE employee_id = &employee_num ;

--  the & prompts user for a input

SELECT last_name, department_id, salary*12
FROM employees
WHERE job_id = '&job_title' ;

-- for date and character values which are string use ''