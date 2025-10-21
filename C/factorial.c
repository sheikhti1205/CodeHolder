#include <stdio.h>
int main()
{
    int i, x, fact =1;

    printf("Enter an integer : \n");
    scanf("%d", &x);

    if(x >= 0)
    {
    for(i = 1; i <= x; i++)
    {
        fact *= i;
    }

    printf("The factorial of given number %d is: %d\n", x, fact);
    }
    else{
        printf("Error!\n");
    }

    return 0;
}