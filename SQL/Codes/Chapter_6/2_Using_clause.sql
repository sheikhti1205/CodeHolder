select employee_id, last_name, location_id, department_id
from employees join departments
using (department_id);