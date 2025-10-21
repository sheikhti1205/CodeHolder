#include <stdio.h>
int main()
{
    int i, j, n, m;

    printf("Enter the value of n:\n");
    scanf("%d", &n);

    m = (n/2)+1;


    for(i=1; i<=n; i++)
    {
        for(j=n; j>=i; j--)
        {
            printf("  ");
        }
        for(j=1; j<=(2*i)-1; j++)
        {
            if(j==1 || j==(2*i)-1)
            {
                printf("* ");
            }
            else if(i==m)
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