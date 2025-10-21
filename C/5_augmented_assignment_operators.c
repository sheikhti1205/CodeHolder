#include <stdio.h>
int main () {
    /* A.A.O = used to replace a statement where an operator 
     takes a variable as one of its arguments
     and then assigns the results back to the same variable
     
     want to do x = x + 1*/
     int a = 10;
     int b = 10;
     int c = 10;
     int d = 10;
     int e = 10;

     //a = a + 2;
     a+=2; 
     b-=3;
     c*=4;
     d/=5;
     e%=2; //modulus is % sign helps find whether a number is odd or even based on the divider

     printf("%d\n", a);
     printf("%d\n", b);
     printf("%d\n", c);
     printf("%d\n", d);
     printf("%d\n", e);
}