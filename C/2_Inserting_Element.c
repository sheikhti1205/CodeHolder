#include <stdio.h>
int main()
{
    int a[10], i;

    for(i=0; i<10; i++)
    {
        a[i] = i+1;
    }

    int p, v;

    printf("Enter Position: ");
    scanf("%d", &p);
    printf("Enter Value: ");
    scanf("%d", &v);

    a[p-1] = v;

    printf("Array: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", a[i]);
    }
}