#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, s, area;

    printf("Enter the values of a, b, c one by one: \n");
    scanf("%f%f%f", &a, &b, &c);

    s = (a + b + c) / 2;

    area = s * (s - a) * (s - b) * (s - c);

    area = sqrt(area);

    printf("The area of the triangle is: %f\n", area);

    return 0;
}