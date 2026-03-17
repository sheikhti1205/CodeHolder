select employee_id, to_char(hire_date, 'MM/YY') Month_Hired
from employees
where last_name = 'Higgins';

-- If you're wondering why...I'm skipping chp 4...:)