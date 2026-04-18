select  count(hire_date),
        count(case when to_char(hire_date, 'YYYY') = '2012' then 1 end) "2012",
        count(case when to_char(hire_date, 'YYYY') = '2013' then 1 end) "2013",
        count(case when to_char(hire_date, 'YYYY') = '2014' then 1 end) "2014",
        count(case when to_char(hire_date, 'YYYY') = '2015' then 1 end) "2015"
from employees
where to_char(hire_date, 'YY') in ('12', '13', '14', '15');