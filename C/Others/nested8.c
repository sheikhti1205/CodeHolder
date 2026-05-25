#include <stdio.h>
int main()
{
    int row, col, n;

    printf("How manyy rows of right triangle?\n");
    scanf("%d", &n);

    for(row=n; row>=1; row--)
    {
        for(col=row; col>=1; col--)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}