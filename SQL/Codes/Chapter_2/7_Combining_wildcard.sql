select employee_id, last_name, job_id
from employees
where job_id like 'SA\_%' escape '\';

-- now you might think why escape character before the '_'
-- well this means any character, but I wan't specifically '_' character nothing else and thus this '\'
-- with the next part escape we're treating it as a underscore instead of a wildcard