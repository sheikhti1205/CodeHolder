#include <stdio.h>
int main()
{
    int i, j, n;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        for(j=n; j>=i-1; j--)
        {
            printf(" ");
        }
        for(j=2; j<=i; j++)
        {
            if(j==2 || j==i || j==n)
            {
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=i; j++)
        {
            printf(" ");
        }
        for(j=n; j>=i; j--)
        {
            if(j==1 || j==i || j==n)
            {
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}