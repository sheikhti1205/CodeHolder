describe employees;

select  employee_id     || ', ' ||
        first_name      || ', ' ||
        last_name       || ', ' ||
        email           || ', ' ||
        phone_number    || ', ' ||
        hire_date       || ', ' ||
        salary          || ', ' ||
        job_id          || ', ' ||
        commission_pct  || ', ' ||
        manager_id      || ', ' ||
        department_id   "The_Output"
from    employees;

-- Describe was used to get the names I need to use