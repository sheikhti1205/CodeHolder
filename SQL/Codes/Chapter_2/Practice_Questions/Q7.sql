SELECT last_name, hire_date
from employees
where hire_date between date '2012-01-01'
                    and date '2012-12-31';

-- Well this is efficient but hard to write for me -_-

-- oh and it seems there's no 1994 so I did 2012

SELECT last_name, hire_date
from employees
where to_char(hire_date, 'yy') = '12';

-- Rather this is preferrable tho it says it's inefficient...
-- seems like it converts then checks and doing it inside where might cause problem or something? It didn't tho...