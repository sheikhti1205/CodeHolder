SELECT job_id, department_id
FROM (
    SELECT job_id, department_id, 1 AS sort_order
    FROM employees
    WHERE department_id = 10

    UNION

    SELECT job_id, department_id, 2 AS sort_order
    FROM employees
    WHERE department_id = 50

    UNION

    SELECT job_id, department_id, 3 AS sort_order
    FROM employees
    WHERE department_id = 20
)
ORDER BY sort_order, job_id;