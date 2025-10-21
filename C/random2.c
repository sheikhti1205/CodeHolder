#include <stdio.h>
int main() {
    int n, m, p;                      // Declare integers n, m, and p
    for (n = 1, m = 50; n <= m; n = n + 1, m = m - 1) {
        p = m / n;                    // Calculate p as the integer division of m by n
        printf("%d %d %d \n", n, m, p); // Print the values of n, m, and p
    }
}
