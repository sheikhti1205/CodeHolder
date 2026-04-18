select  round(months_between(to_date('31-DEC-26', 'DD-MON-RR'), to_date('01-FEB-26', 'DD-MON-RR')), 2) "Diff",
        add_months(to_date('01-FEB-26', 'DD-MON-RR'), 1) "Add_Func",
        next_day(to_date('01-FEB-26', 'DD-MON-RR'), 'FRIDAY') "Next Friday is in",
        last_day(to_date('01-JAN-71', 'DD-MON-RR')) "Last day of the month"
from dual;