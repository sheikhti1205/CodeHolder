SELECT employee_id, last_name, job_id, &&column_name
FROM employees
ORDER BY &column_name ;

-- the double && means it's a variable can show any column
-- i just need to name it right tho