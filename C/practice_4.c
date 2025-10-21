#include <stdio.h>
int main()
{
    int a, b = 1, c = 1;
    //then
    a = sizeof(c = ++b + 1);

    //basically a is equal to the size of int c.
    //the size of int is always 4 so the answer will be 4 not 3 or something else duh!
    //c and b won't change cause we're doing incrementation in a way which will do the work in runtime
    //not compilation time. So, value won't change.

    printf("a equals to: %d,\nb equals to: %d,\nc equals to: %d,\n", a, b, c);

}
