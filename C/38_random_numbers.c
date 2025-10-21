#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /*
    Pseudo random numbers = A set of values or elements that are statistically random
    (Don't use these for any sort of cryptographic security)
    */

   srand(time(0));

   int num1 = (rand() % 20) + 1;
   int num2 = (rand() % 20) + 1;
   int num3 = (rand() % 20) + 1;
   int num4 = (rand() % 20) + 1;  //0-32767

   printf("%d\t", num1);
   printf("%d\t", num2);
   printf("%d\t", num3);
   printf("%d\t", num4);

   return 0;
}