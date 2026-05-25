#include <stdio.h>
int main() {
    //array = a data structer that can store many values of the same data type.

    double prices[] = {5.0, 4.0, 35.0, 20.0, 25.0, 45.0, 9.0, 25.6, 97.9};

    /*  
    prices[0] = 5.0;
    prices[1] = 15.0;
    prices[2] = 25.0;
    prices[3] = 20.0;
    prices[4] = 35.0;  */


    //printf("%.2lf$\n", prices[2]);  //starts with 0,1,2,3,4...

    //printf("%d bytes\n", sizeof(prices));

    

    for(int i = 0; i < sizeof(prices)/sizeof(prices[0]); i++) {
        printf("%.2lf$\n", prices[i]);
    }
    

    return 0;
}