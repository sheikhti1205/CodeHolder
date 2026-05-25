#include <stdio.h>
int main()
{
    float n, x;

    printf("Enter the value of n: \n");
    scanf("%f", &n);

    x = 2 * n * (n + 1) * ( (2 * n) + 1) / 3;

    //   2/3(n(n+1)(2n+1))

    printf("the sum of the given math problem is: %.2f\n", x);

    return 0;
}