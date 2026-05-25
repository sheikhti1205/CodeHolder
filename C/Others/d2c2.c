#include <stdio.h>
#include <math.h>
int main()
{
    double x;

    printf("Enter the value of x: \n");
    scanf("%lf", &x);

    x = pow(x, 1.0/3.0);

    printf("Output is: %lf", x);

    return 0;
}