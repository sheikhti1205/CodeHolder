#include <stdio.h>

int math(double a, double b);

int main()
{
    double x = 8.8;
    double y = 8;

    // x replaces a, y replaces b

    math(x, y);
}

int math(double a, double b)
{
    printf("Sum is %.2lf", a+b);
}