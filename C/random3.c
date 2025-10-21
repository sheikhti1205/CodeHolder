#include <stdio.h>
void main() {
    int x = 3, y = 1;
    if(x >= 5 || x % 2 != 0) {
        x++;
        y = x + y;
    } else {
        y++;
    }
    printf("%d %d", x, y);
}
