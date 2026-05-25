#include <stdio.h>
int main() {
    //nested loop = a loop within a loop

    int row;
    int col;
    char sym;

    printf("\nEnter # of rows:\n");
    scanf("%d", &row);

    printf("\nEnter # of columns:\n");
    scanf("%d", &col);

    scanf("%c");

    printf("\nEnter a symbol to use:\n");
    scanf("%c", &sym);

    for(int i = 1; i <= row; i++) {
        for(int j =1; j <= col; j++) {
            printf("%c", sym);
        }
        printf("\n");
    }

    return 0;
}