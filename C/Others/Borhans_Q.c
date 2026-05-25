#include <stdio.h>
int main()
{
    int n1, n2, i, count_0 = 0, count_1 = 0;
    printf("How many numbers do you want? :\n");
    scanf("%d", &n1);
    for(i=0; i<n1; i++)
    {
        printf("Enter either '0' or '1'\n");
        scanf("%d", &n2);
        if(n2==0)
        {
            count_0++;
        }
        else if(n2=1)
        {
            count_1++;
        }
    }    

    printf("\nTotal Number of 'ZERO' is %d\n\n", count_0);
    printf("Total Number of 'ONE' is %d", count_1);
}