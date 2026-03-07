select concat('hello', 'WoRlD') from dual;

-- Concat only accepts two args so three words won't work

select substr('HelloWorld', 1, 5) from dual;

-- Start from index 1 print first 5 characters

select length('hello world') from dual;

-- It does consider space. But the col_name seems to be space_less >x<

SELECT INSTR('abcdefghijklmnopqrstuvwxyz', '&val') from dual;

-- Takes user input and then checks the position of that value
-- NEW LESSON - "Don't type comments after the &something. It interprets that as user input"

select lpad(salary, 10, '*') from dual;