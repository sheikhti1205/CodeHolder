select  employee_id, hire_date, 
        round(months_between(sysdate, hire_date), 0) "Days Worked",
        add_months(hire_date, 6) "6th Month Fulfilled in",
        next_day(hire_date, 'FRIDAY') "Next Day",
        last_day(hire_date) "Last Day"
from employees
where months_between(sysdate, hire_date) < 100;