#include <stdio.h>
int main()
{
    int num[10],n,i;
    
    printf("How many numbers do You want to use 1 - 10\n");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter value for %d%s number\n", i+1, (i == 0) ? "st" : 
                                                     (i == 1) ? "nd" : 
                                                     (i == 2) ? "rd" : "th");
        scanf("%d", &num[i]);
    }

    int max = num[0];

    for(i=1; i<n; i++)
    {
        if(max<num[i])
        {
            max=num[i];
        }
    }

    printf("Maximum value is %d", max);
}