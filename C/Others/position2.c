#include <stdio.h>
#include <math.h>
int main()
{
    double x, y, d, b, c;

    printf("Enter the value for x and y: \n");
    scanf("%lf%lf", &x, &y);

    b = (5 - x);
    c = (7 - y);
    d = sqrt((b*b + c*c));

    if(d <= 7)
    {
        printf("The given point is inside the circle\n");
    }
    else
    {
        printf("The given point is outside the circle\n");
    }
    return 0;
}