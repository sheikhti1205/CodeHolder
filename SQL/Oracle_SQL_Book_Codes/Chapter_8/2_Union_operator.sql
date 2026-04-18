select *
from (select employee_id, job_id
    from employees
    union
    select employee_id, job_id
    from job_history)
where employee_id = 200;

-- here the main content is within the brackets.
-- but to show that union did not eliminate these two with employee_id 200
-- mainly cause their job_id is different