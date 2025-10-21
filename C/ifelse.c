#include <stdio.h>
int main()
{
    float f=0.1;
    if(f == 0.1) //0.1 is a double
    //float is less precise than double
    //and since both float and double acts differently
    // they are not equal
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }    
}