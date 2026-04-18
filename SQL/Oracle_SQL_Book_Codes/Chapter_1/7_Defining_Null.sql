select last_name, job_id, salary, commission_pct
from employees;

--Tho it says null should show null and null isn't the same as blank or zero '0' it's showing blank...

/*
If a row lacks a data value for a particular column, that value is said to be null or to contain a null. 

Null is a value that is unavailable, unassigned, unknown, or inapplicable. 

🤐Null is not the same as zero or a blank space. Zero is a number and blank space is a character. 

Columns of anydata type can contain nulls. However, some constraints (NOTNULLand PRIMARY 
KEY) prevent nulls from being used in the column. 

In the COMMISSION_PCTcolumn in the EMPLOYEEStable, notice that only a sales manager or 
sales representative can earn a commission. Other employees are not entitled to earn commissions. 

A null represents that fact.
*/