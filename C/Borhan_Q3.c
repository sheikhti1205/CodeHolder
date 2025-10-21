#include <stdio.h>
int main()
{
    int i,j,n,a,b;
    printf("How many numbers do you want?\n: ");
    scanf("%d", &n);

    /*for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j<=i)
            {
                printf(" ");
            }
        }
        printf(".\n");
    }
    */

   for(i=0;i<=n;i++)
   {
    for(j=0;j<=i;j++)
    {
        printf("%d", j);
    }
   }
}