#include <stdio.h>
#include <math.h>
int main () {
    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\nEnter the radius of the circle:");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;
    area = PI * radius * radius;
    printf("\nCircumference is : %lf", circumference);
    printf("\nArea is =%lf", area);

    return 0;
}