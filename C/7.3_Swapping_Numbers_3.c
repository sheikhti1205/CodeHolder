#include <stdio.h>
#include <conio.h>
int main()
{
    //Using BITWISE OPERATOR XOR
                //2561286432168421
    int x = 12; //-0--0--0-0-01100 (8 + 4) (0-0000-0011)
    int y = 93; //-0--0--1-0-11101 (64 + 16 + 8 + 4 + 1) (0-0101-1101)
//  The "^" indicates to XOR operator.
//  XOR = for every difference between x & y in binary value it adds 1 to the newly appointed location
//  based on both values.
    x = x^y; // (0-0101-0001) (64 + 16 + 1) = 81
    y = x^y; // (0000-0110) (8 + 4) = 12 
    x = x^y; // (0101-1101) (64 + 16 + 8 + 4 + 1) = 93

    printf("X is %d & Y is %d", x, y);

    return 0;
}