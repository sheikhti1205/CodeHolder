select last_name, round(months_between(sysdate, hire_date)) "Months_Worked"
from employees;