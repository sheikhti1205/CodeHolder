#include <stdio.h>
int main()
{
    int n = 3, i=0, j;

    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    //int i = 10;

    printf("%d\n", i);

    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
    {
        printf("%d ", arr[i][j]);
    }
    printf("\n");
    }

    
}