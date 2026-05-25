#include <stdio.h>
int main()
{
    int n, x, i;
    printf("How many numbers do you want? :\n");
    scanf("%d", &n);
    int arr[n];

    printf("Enter the values you want to use in the array one by one.\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        printf("...%d\n", i+1);
    }

    printf("Enter the position you want to modify. :\n");
    scanf("%d", &x);

    if(x>=1 && x<=n)
    {
        if(arr[x-1] == 0)
        {
            arr[x-1] = 1;
        }
        else if(arr[x-1] == 1)
        {
            arr[x-1] = 0;
        }
    }

    for(i=0; i<n; i++)
    {
        printf("%d\n", arr[i]);
    }
}