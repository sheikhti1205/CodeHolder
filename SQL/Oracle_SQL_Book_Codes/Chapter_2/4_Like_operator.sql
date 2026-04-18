SELECT first_name
from employees
where first_name like 'S%';

/*
Use the LIKE operator to perform wildcard searches of valid search string values.
• Search conditions can contain either literal characters or numbers:
    – % denotes zero or many characters.
    – _ denotes one character.
Pattern Matching Using the LIKE Operator:
You may not always know the exact value to search for. You can select rows that match a character 
pattern by using the LIKE operator. The character pattern–matching operation is referred to as a wildcard search. 
Two symbols can be used to construct the search string.
The SELECT statement in the slide returns the first name from the EMPLOYEES table for any
employee whose first name begins with the letter “S.” 
Note the uppercase “S.” Consequently, names beginning with a lowercase “s” are not returned.
The LIKE operator can be used as a shortcut for some BETWEEN comparisons. The following
example displays the last names and hire dates of all employees who joined between January, 1995 and December, 1995:

Symbol Description
% Represents any sequence of zero or more characters
_ Represents any single character
*/

SELECT last_name, hire_date
FROM employees
WHERE hire_date LIKE '%1_';

-- can test with %12, which will return all year ending with 12
-- then there's %__, this is two '_' so it will be any two numbers

-- current example tells the the interpreter to return any date with the year starting with the 10th
-- e.g. - 10, 11, 12, 13, 14, 15, 16, 17.... and so on....

-- Another example:

SELECT last_name
FROM employees
WHERE last_name LIKE '_o%' ;