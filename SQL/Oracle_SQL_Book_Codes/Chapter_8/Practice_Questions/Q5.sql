SELECT last_name, department_id, TO_CHAR(NULL) AS department_name
FROM employees

UNION

SELECT TO_CHAR(NULL) AS last_name, department_id, department_name
FROM departments;