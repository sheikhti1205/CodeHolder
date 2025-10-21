#include <stdio.h>
void main() {
    int arr[5], i=0;
    while(i<5)
    {
        arr[i] = ++i;
    }
    for(i=0; i<5; i+=2)
    {
        printf("%d, ", arr[i]);
    }
}
