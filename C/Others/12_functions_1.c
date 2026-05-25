#include <stdio.h>
#include <ctype.h>
int main () {
    char unit;
    float temp;

    printf("\nIs the temparature in (F) or (C)?:");
    scanf("%c", &unit);

    unit = toupper(unit);

    if(unit == 'C'){
        printf("The temp. is currently in Celcius\n");
        printf("Enter the temp. in Celcius: ");
        scanf("%f", &temp);
        temp = (temp * 9 / 5) + 32;
        printf("\nThe temp. in Farenheit is %.1f Degree Farenheit", temp);
    }
    else if(unit == 'F'){
        printf("The temp. is currently in Farenheit\n");
        printf("Enter the temp. in Farenheit: ");
        scanf("%f", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf("\nThe temp. in Celcius is %.1f Degree Celcius", temp);
    }
    else{
        printf("\n %c is not a valid unit of measurement");
    }


    return 0;
}