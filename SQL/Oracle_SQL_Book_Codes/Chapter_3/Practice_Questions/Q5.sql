select initcap(last_name) "Name", length(last_name) "Length"
from employees
where last_name like 'J%'
or last_name like 'A%'
or last_name like 'M%'
order by last_name;
-- Part 2 & 3 done at once --
select initcap(last_name) "Name", length(last_name) "Length"
from employees
where last_name like initcap('&var%');