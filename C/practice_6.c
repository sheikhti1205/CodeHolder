#include <stdio.h>
int main()
{
    int a = 1, b = 3, c = 2;

    if(a > b)
         if(b > c)
         {
            printf("a is greater than b and b is greater than c");
         }
    else
    {
        printf("something else");
    }
    //no output cause the else belongs to 2nd if and the entire 2nd part will only work if
    //the first if condition is true. which isn't true.
    
}