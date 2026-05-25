#include <stdio.h>
int main () {

    char operator;
    double num1;
    double num2;
    double result;

    printf("\nEnter an operator: (+ - * /)");
    scanf("%c", &operator);
    printf("\nEnter number 1: \n");
    scanf("%lf", &num1);
    printf("\nEnter number 2: \n");
    scanf("%lf", &num2);

    switch(operator){
        case '+':
           result = num1 + num2;
           printf("\nThe additon is %.2lf", result);
           break;
        case '-':
           result = num1 - num2;
           printf("\nThe substraction is %.2lf", result);
           break;
        case '*':
           result = num1 * num2;
           printf("\nThe multiplication is %.2lf", result);
           break;
        case '/':
           result = num1 / num2;
           printf("\nThe division is %.2lf", result);
           break;
        default:
           printf("\n%c This operator is not valid", operator);
        
    }

    return 0;
}