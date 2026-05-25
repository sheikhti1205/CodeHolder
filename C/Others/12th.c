#include <stdio.h>
int main()
{
    int n, i, j;

    for(i=1;i<=5;i++)
        {
            if(i%2==0)
            {
                printf(" *");
            }
            else if(i==1 || i==3 || i==5)
            {
                for(j=1;j<=i;j++)
                {
                    printf("* ");
                    if(i==5)
                    {
                        break;
                    }
                }
            }
            /*else
            {
                printf("*");
            }*/
            printf("\n");
        }
}
