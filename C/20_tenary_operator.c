#include <stdio.h>

int findmax(int x, int y) {

    /* if(x > y) {
        return x;
    }
    else{
        return y;
    } */

    return (x > y) ? x : y;
}
int main() {
    // Tenary operator = shortcut to if/else when assigning/returning a value
    //(condition) ? value if true : value if false

    int max = findmax(5, 4);

    printf("%d", max);

    return 0;
}