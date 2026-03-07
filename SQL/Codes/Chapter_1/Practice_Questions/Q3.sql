-- SELECT    employee_id, last_name
-- sal x 12  ANNUAL SALARY
-- FROM      employees;

-- The above code is wrong. Correct is:

SELECT employee_id, last_name, salary*12 as "Annual Salary"
FROM employees;