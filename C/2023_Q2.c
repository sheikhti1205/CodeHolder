#include <stdio.h>
int main()
{
    int n = 5,i,j;

    for(i=0; i<5; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i % 2 == 0)
            {
                printf("+ ");
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }
}