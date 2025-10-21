#include <stdio.h>
int main () 
{
    int x;
    int y;

    printf("Enter the value of X: \n(0-1000)\n");
    scanf("%d", &x);
    printf("Enter the value of Y: \n(0-1000)\n");
    scanf("%d", &y);

    if(x > y && x < 1000 && y < 1000)
    {
        printf("X is greater than Y");
    }
    else if(x < y && x < 1000 && y < 1000)
    {
        printf("X is less than Y");
    }
    else if(x == y && x < 1000 && y < 1000)
    {
        printf("X is equal to Y");
    }
    else
    {
        printf("Error! Value exceeds storage limit!");
    }
}