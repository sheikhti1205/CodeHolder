#include <stdio.h>
int main() {
    /* Memory = an array of bytes within RAM (street)
    memory block = a single unit (byte) within memory, used to hold some value (person)
    memory address = the address of where a memory block is located (house address)*/

    char a;
    double b[3];
    char c = 'Z';

    printf("%d bytes\n", sizeof(a));
    printf("%d bytes\n", sizeof(b));
    printf("%d bytes\n", sizeof(c));

    printf("%p\n", &a);
    printf("%p\n", &b);
    printf("%p\n", &c);

    return 0;
}