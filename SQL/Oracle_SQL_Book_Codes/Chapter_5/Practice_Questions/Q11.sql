select  job_id, 
        sum(case when department_id = 20 then salary end) "Department 20",
        sum(case when department_id = 50 then salary end) "Department 50",
        sum(case when department_id = 80 then salary end) "Department 80",
        sum(case when department_id = 90 then salary end) "Department 90",
        sum(salary) "Total"
from employees
group by job_id
order by job_id;