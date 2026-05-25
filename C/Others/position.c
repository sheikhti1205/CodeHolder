#include <stdio.h>
int main()
{
    double x, y;

    printf("Enter the value for x and y: \n");
    scanf("%lf%lf", &x, &y);

    (x>=2 && x<=5 && y>=1 && y<=6) ? printf("The given point is inside the rectangle\n") :
    printf("The given point is outside the rectangle\n");

    /*if(x>=2 && x<=5 && y>=1 && y<=6)
    {
        printf("The given point is inside the rectangle\n");
    }
    else
    {
        printf("The given point is outside the rectangle\n");
    }*/

    return 0;
}