#include <stdio.h>
#include <conio.h>
int main()
{
    //using Addition & Substraction
    int x = 12;
    int y = 16;

    x = x + y - (x = y);

    printf("X is %d & Y is %d", x, y);
    
    return 0;
}