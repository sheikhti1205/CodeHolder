#include <stdio.h>
int main() {
    int x = 0, y = 5, i = 2; // Initialize x=0, y=5, i=2
    while (i--) {            // Loop runs while i is greater than 0. After each iteration, i decreases by 1.
        x += 1;              // Increment x by 1
        y = 1;               // Set y to 1
        printf("\nX=%d\nY = %d", x, y); // Print the values of x and y
    }
}
