select lpad(salary, 10, '*') from employees;

-- LPAD(expression, total_length, pad_character)
-- pad_count = total_length − length(expression)
-- So the number of * depends on how long the original value is.
-- example:
SELECT LPAD('5000', 10, '*')
FROM dual;
-- Here 10 - 4 = 6; and thus 6 stars.