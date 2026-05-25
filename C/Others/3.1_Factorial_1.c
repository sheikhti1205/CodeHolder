#include <stdio.h>
int main()
{
    int i;
    int n = 0;
    int fact = 1;

    //Factorial of any number

    printf("Enter a Number: \n");
    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    };


    printf("Factorial of %d is %d", n, fact);

    return 0;
}