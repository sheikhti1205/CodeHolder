#include <stdio.h>
int main()
{
    int n;

    //Try not to exceed 20. Cause it isn't gonna look good.

    printf("How Many Elements Do You Want To Work With?\n");
    scanf("%d", &n);

    int a[n], i, position;
    
    for(i=0; i<n; i++)
    {
        a[i] = i+1;
    }

    //Delete the one in 4th position

    printf("Choose Your Position: ");
    scanf("%d", &position);

    if(position<1 || position>n)
    {
        printf("Error!");
    }
    else
    {
    for(i=position-1; i<n-1; i++)
    {
        a[i] = a[i+1];
    }

    a[i] = 0;

    printf("Array: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    }
}