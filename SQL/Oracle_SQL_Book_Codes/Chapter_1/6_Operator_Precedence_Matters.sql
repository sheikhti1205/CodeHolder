select last_name, salary, 12*salary+100, 12*(salary+100)
from employees;

/*
Operator Precedence:
If an arithmetic expression contains more than one operator, multiplication and division are evaluated 
first. If operators in an expression are of the same priority, then evaluation is done from left to right.

You can use parentheses to force the expression that is enclosedby the parentheses to be evaluated 
first.

Rules of Precedence:
    • Multiplication and division occur before addition and subtraction.
    • Operators of the same priority are evaluated from left to right.
    • Parentheses are used to override the default precedence or to clarify the statement.
*/