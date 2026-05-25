#include <stdio.h>
#include <math.h>
int main()
{
    float n, x;

    printf("Enter the value of n: \n");
    scanf("%f", &n);

    x = n * ((4 * (n * n) -1)) / 3;

    //   n ( (4n^2) -1 ) / 3

    printf("the sum of the given math problem is: %.2f\n", x);

    return 0;
}