#include <stdio.h>
int main() {
    //while loop checks a condition, then executes a block of code
    //do while executes once then checks a condition

    int num = 0;
    int sum = 0;

    do{
        printf("\nEnter a number above 0:\n");
        scanf("%d", &num);
        if(num > 0) {
            //sum = sum + num;
            sum += num;
        }
    }while(num > 0); 

    printf("Sum: %d", sum);

    return 0;
}