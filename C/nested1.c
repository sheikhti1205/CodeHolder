#include <stdio.h>
int main()
{
    int row, col, n;

    printf("How manyy rows of square?\n");
    scanf("%d", &n);

    for(row=1; row<=n; row++)
    {
        for(col=1; col<=n; col++)
        
            printf("* ");
        
        printf("\n");
    }

    return 0;
}