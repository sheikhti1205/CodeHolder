 #include <stdio.h>
 int main () {
    // + addition
    // - substraction
    // * multiplication
    // / division
    // % modulus (gives the remainder of any division, helps to find even and odd numbers)
    // ++ increment ( increments by one or x+1 something like that)
    // -- deccrement ( deccrement by one or x-1 something like that)

    int x = 12;
    int y = 16;

    int z = x + y;
    printf("%d\n", z);
    int w = x - y;
    printf("%d\n", w);

    float a = y / (float) x; 
    /*to get the decimal portion either the
     divider needs to be float or double or this*/
    printf("%f\n", a);

    int s = x % y;
    printf("%d\n", s);

    x++;
    y--;
    printf("%d\n", x);
    printf("%d\n", y);

    return 0;
 }