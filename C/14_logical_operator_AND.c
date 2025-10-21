#include <stdio.h>
#include <stdbool.h>
int main () {
    //logical operator = && (AND) checks if two conditions are true

    float temp;
    printf("Enter current temp: \n");
    scanf("%f", &temp);
    bool sun = 1; //(true = 1 false = 0)

    if(temp >= -40  && temp <= 0 && sun == 1){
        printf("\nThe weather is Cold");
    }
    else if(temp >= 100){
        printf("\nThe weather is Catastrophic");
    }
    else if(temp <= 50 && temp > 0){
        printf("\nThe weather is Good");
    }
    else{
        printf("\nThe weather is Abnormal");
    }

    return 0;
}