#include <stdio.h>
int main()
{
    int i, j, n, m;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    m = n;

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==1 || i==n)
            {
                printf("* ");
            }
            else if(j==m-1)
            {
                printf("* ");
                m--;
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
}