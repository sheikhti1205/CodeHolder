#include <stdio.h>
int main() 
{
    float f = 0.1; //will result in false
    //double f = 0.1; //will result in true

    if(f == 0.1)
    //if(f == 0.1f); //will result in true as the f of 0.1f defines it as a float
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

/*
IN  FLOAT THE value is 32 bit in DOUBLE 64 bit
but here the 0.1 in if() is set to double by defalut

SOLUTION:
either change float to double or set the value of if() to 0.1f to define it as a float*/