#include <stdio.h>
int main()
{
    int i, j, n, m=1;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    for(i=0; i<=n; i++)
    {
        for(j=n; j>=i; j--)
        {
            printf(" ");
        }
        m=1;
        for(j=0; j<=i; j++)
        {
            printf("%d ", m);
            m = m*(i-j)/(j+1);
        }
        printf("\n");
    }
}