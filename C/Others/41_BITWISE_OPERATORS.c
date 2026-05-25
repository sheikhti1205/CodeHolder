#include <stdio.h>
int main() {
    /* BITWISE OPERATOR = special operators used in bit level programming
                          (knowing binary is important for this topic!)*/
    // & = AND
    // | = OR
    // ^ = XOR
    // << = left shift
    // >> = right shift

    int x = 6; //6 = 00000110
    int y = 12; //12 = 00001100
    int z = 0; // 0 = 00000000

    z = x & y;
    printf("AND = %d\n", z);

    z = x | y;
    printf("OR = %d\n", z);

    z = x ^ y;
    printf("XOR = %d\n", z);

    z = x << 4; // 6 = 00000110 -- shift 4 ==48 = 00110000 -- shift 3 ==00011000 
    printf("LEFT SHIFT = %d\n", z);

    z = x >> 2; // 6 = 00000110 -- shift 1 ==3 = 00000011 -- shift 2 ==1 = 00000001 
    printf("RIGHT SHIFT = %d\n", z);

    return 0;
}