SELECT location_id, department_name "Department", to_char(NULL) "Warehouse Location"
from departments
UNION
SELECT location_id, to_char(NULL) "Department", state_province
from locations;