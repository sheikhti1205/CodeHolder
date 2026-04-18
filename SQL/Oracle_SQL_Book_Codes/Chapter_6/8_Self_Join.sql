select worker.last_name, manager.last_name
from employees worker join employees manager
on (worker.manager_id = manager.employee_id);