select substr(last_name, 1, 8) || ' ' || rpad('*', salary/1000, '*') "Employees and their salary"
from employees;