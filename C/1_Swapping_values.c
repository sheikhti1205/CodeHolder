#include <stdio.h>
int main()
{
    int a[100], b[100], i, j, n;

    printf("How many numbers or elements do you want?\n:");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter the elements in order-\n");
        scanf("%d", &a[i]);
    }
    for(i=n-1, j=0; i>=0; i--, j++)
    {
        b[j] = a[i];
    }
    for(i=0; i<n; i++)
    {
        a[i] = b[i];
    }
    printf("Reversed array is: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}