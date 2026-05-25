#include <stdio.h>
int main()
{
    int i, j, n;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            if(j==1)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        for(j=n; j>=i; j--)
        {
            printf("*");
        }
        for(j=1; j<=i; j++)
        {
            if(j==i)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i=1; i<=n-1; i++)
    {
        for(j=n-1; j>=i; j--)
        {
            if(j==n-1)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        for(j=1; j<=i+1; j++)
        {
            printf("*");
        }
        for(j=n; j>=i; j--)
        {
            if(j==i+1)
            {
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}