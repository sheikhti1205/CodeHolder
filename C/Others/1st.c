#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int x1, x2, y1, y2, r1, r2, d1, d2;

    printf("Enter the x and y of first circle and it's radius:\n");
    scanf("%d%d%d",&x1,&y1,&r1);
    printf("Enter the x and y of second circle and it's radius:\n");
    scanf("%d%d%d",&x2,&y2,&r2);

    d1 = (((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2 - y1)));
    d1 = sqrt(d1);

    d2 = (r1 + r2);

    
    if(d1 == d2)
    {
        printf("They touch each other externally\n");
    }
    else if(d1<fabs(r1-r2))
    {
        printf("one is inside the other\n");
    }
    else if(d1 < d2)
    {
        printf("They intersect each other\n");
    }

    return 0;
}