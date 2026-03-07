SELECT last_name, 12*(salary*commission_pct)
from employees;

--As it says--

/*
If any column value in an arithmetic expression is null, the result is null. For example, if you attempt 
to perform division by zero, you get an error. However, if you divide a number by null, the result is a 
null or unknown. 
In the example in the slide, employee King does not get any commission. Because the 
COMMISSION_PCTcolumn in the arithmetic expression is null, the result is null. 
*/