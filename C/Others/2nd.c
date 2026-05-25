#include <stdio.h>
int main()
{
    int temphi, tempmin, hum, rain, sun, sat = 0;

    printf("Enter the Highest Temparature\n");
    scanf("%d", &temphi);
    printf("Enter the Lowest Temparature\n");
    scanf("%d", &tempmin);
    printf("Enter the Humidity\n");
    scanf("%d", &hum);
    printf("Enter the Rainfall amount\n");
    scanf("%d", &rain);
    printf("Enter the Sunshine\n");
    scanf("%d", &sun);

    if(temphi>= 31 && temphi<= 34)
    {
        sat += 1;
    }
    if(tempmin>= 22 && tempmin<= 23)
    {
        sat += 1;
    }
    if(hum>= 89 && hum<= 92)
    {
        sat += 1;
    }
    if(rain>= 0 && rain<= 10)
    {
        sat += 1;
    }
    if(sun>= 6 && sun<= 9)
    {
        sat += 1;
    }
    
    if(sat>3)
    {
        printf("High\n");
    }
    else if(sat==3)
    {
        printf("Moderate\n");
    }
    else if(sat<3)
    {
        printf("No\n");
    }
    return 0;
}