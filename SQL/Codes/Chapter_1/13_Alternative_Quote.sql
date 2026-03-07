select department_name || q'[ Department's Manager ID: ]' || manager_id
    as "Department and Manager"
from departments;

/*
Many SQL statements use character literals in expressions or conditions. If the literal itself contains a 
single quotation mark, you can use the quote (q) operator and select your own quotation mark 
delimiter.
You can choose any convenient delimiter, single-byte or multibyte, or any of the following character 
pairs: [ ], { }, ( ), or < >.
In the example shown, the string contains a single quotation mark, which is normally interpreted as a 
delimiter of a character string. By using the qoperator, however, brackets [] are used as the quotation 
mark delimiters. The string between the brackets delimiters is interpreted as a literal character string.
*/