#include <stdio.h>
int main()
{
    int i, j, n, m, l;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    m = (n/2)+1;
    l = m;


    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(j==m || j==l || (i==(n/2)+1 && j>=m && j<=l))
            {
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        if(i<(n/2)+1)
            {
                m--;
                l++;
            }
        printf("\n");
    }
}