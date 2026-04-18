select last_name||job_id as "Employees"
from employees;

/*
You can link columns to other columns, arithmetic expressions, or constant values to create a 
character expression by using the concatenation operator (||). Columns on either side of the operator 
are combined to make a single output column.
In the example, LAST_NAMEand JOB_IDare concatenated, and given the alias Employees. Note 
that the last name of the employee and the job code are combinedto make a single output column.
The ASkeyword before the alias name makes the SELECTclause easier to read.
Null Values with the Concatenation Operator
If you concatenate a null value with a character string, the result is a character string. LAST_NAME 
||NULLresults in LAST_NAME.

Note:You can also concatenate date expressions with other expressions or columns.
*/