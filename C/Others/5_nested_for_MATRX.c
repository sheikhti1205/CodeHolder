#include <stdio.h>
int main()
{
    int i, j, k;

    //MATRIX with nested for loop

    printf("\t\t\t\t-___________________________________________________________-\n");

    for(i = 0; i < 10; i++)
    {
        printf("%d\t\t\t\t", i);

        for(j = 0; j < 10; j++)
        {
            printf("| _%d_ ", j);
        }

        printf("| \n");
    }

    printf("\t\t\t       THIS IS HOW YOU MAKE A 10X10 MATRIX IN C WITH NESTED FOR LOOPS!\n");

    return 0;
}