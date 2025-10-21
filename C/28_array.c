#include <stdio.h>
int main() {
    //array = a data structer that can store many values of the same data type.

    double prices[5]; // = {5.0, 4.0, 35.0; 20.0, 25.0};

    prices[0] = 5.0;
    prices[1] = 15.0;
    prices[2] = 25.0;
    prices[3] = 20.0;
    prices[4] = 35.0;


    printf("%.2lf$", prices[2]);  //starts with 0,1,2,3,4...

    return 0;
}