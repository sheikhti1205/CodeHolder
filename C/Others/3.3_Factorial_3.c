#include <stdio.h>
int main()
{
    int i = 1;
    int n = 0;
    int fact = 1;

    printf("Enter a number: \n");
    scanf("%d", &n);

    if(n >= i)
    {
        do
        {
            fact = fact * i;
            i++;
        }
        while(i <= n);
    }

    printf("Factorial of %d is: \n%d", n, fact);

    return 0;
}