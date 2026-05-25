#include <stdio.h>
void main() {
    int i = 3;
    while(1) {
        if(i <= 50) {
            if((i % 2!=0) && (i < 50))
                i = i*2;
            else
                i = i*3;
        }
        if(i == 54)
            break;
        printf("%d ", i);
    }
}
