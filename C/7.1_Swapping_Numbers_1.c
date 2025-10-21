#include <stdio.h>
#include <conio.h>
int main()
{
    int x = 10;
    int y = 15;
    int temp;
    //swapping values of x & y with the help of a temp
    temp = x;
    x = y;
    y = temp;

    printf("X is %d & Y is %d", x, y);

    return 0;
}