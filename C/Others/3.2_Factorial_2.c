#include <stdio.h>
int main()
{
    int i = 1;
    int n = 0;
    int fact = 1;

    printf("Enter a number: \n");
    scanf("%d", &n);

    while(i <= n)
    {
        fact = fact * i;
        i++;
    }

    printf("Factorial of %d is: \n\t%d\t\n", n, fact);

    return 0;
}