#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n, i, j;

    srand(time(NULL));

    printf("enter the array limit\n");
    scanf("%d", &n);

    //n = rand() % 100;

    int arr[n];

    srand(time(NULL));

    for(i=0; i<n; i++)
    {
        arr[i] = rand()%10;
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Do you want to replace a number? y or n\n");
    char prompt; getchar();
    scanf("%c", &prompt);

    (prompt != n) ? (printf("You choose yes!\n")) : (printf("You choose No!"));
}