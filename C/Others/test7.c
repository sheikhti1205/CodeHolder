#include <stdio.h>
int main()
{
    int a, b, c;

    printf("Enter the values of a, b & c respectively: \n");
    scanf("%d%d%d", &a, &b, &c);

    (a < b && a < c) ? printf("A is Smallest\n") : 
    (b < c && b < a) ? printf("B is Smallest\n") : 
    (c < b && c < a) ? printf("C is Smallest\n") : printf("Wrong Input\n");

    return 0;
}