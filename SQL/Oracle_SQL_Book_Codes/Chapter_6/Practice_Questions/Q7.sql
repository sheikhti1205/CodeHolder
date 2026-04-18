desc job_grades;

select e.last_name, e.job_id, d.department_name, e.salary, g.grade_level
from employees e join departments d
on (e.department_id = d.department_id)
join job_grades g
on (e.salary between g.lowest_sal and g.highest_sal);
