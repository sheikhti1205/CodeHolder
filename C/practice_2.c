#include <stdio.h>
int main()
{
    if(sizeof(int) > -1)  //results to false
    //if ((int)sizeof(int) > -1) //results to true
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    printf("%d\n", sizeof(int)); //on both 32 and 64 bit operating system size of int is
                                 // 4 byte or 32 bit
}

/*
The expression sizeof(int) > -1 evaluates to false in C because of the following reasons:

##Type Mismatch:
1. The sizeof(int) expression returns the size of an int in bytes. It has type size_t, 
which is an unsigned integer type.
2. On the other hand, -1 is a signed integer literal with type int.
3. When comparing a signed integer with an unsigned integer, 
the signed integer is implicitly converted to an unsigned integer.
4. So, sizeof(int) is compared against a very large unsigned value (usually equal to UINT_MAX), 
which is greater than -1.
5. As a result, the comparison evaluates to false.

##Implicit Conversion:
1. The usual arithmetic conversion rules apply here.
2. The -1 literal is converted to an unsigned integer type (the same type as sizeof(int)), 
resulting in a large positive value.
3. This conversion leads to the unexpected behavior in the comparison.
4. To avoid this issue, you can explicitly cast sizeof(int) to a signed integer before comparing:

#include <stdio.h>

int main() {
    if ((int)sizeof(int) > -1) {
        printf("\nTrue\n");
    } else {
        printf("\nFALSE\n");
    }
}
*/