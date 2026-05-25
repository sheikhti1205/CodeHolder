#include <stdio.h>
#include <math.h>

void main_board_upper();
void main_board_lower();
void Choice();
void math();

int main()
{
    Choice();
    math();
    return 0;
}

//UPPER PART
void main_board_upper()
{
    printf("|----------------------------|\n");
    printf("| ");
}
//LOWER PART
void main_board_lower()
{
    printf("|----------------------------|\n");
}
//CHOICE
void Choice()
{
    
    
}
//MATH
void math()
{
    
    double x;
    double y;
    //taking inputs
    printf("Enter First number: ");
    scanf("%lf", &x);
    
    printf("Enter Second number: ");
    scanf("%lf", &y);


    main_board_upper();
    printf("Choose a math operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exponentiation\n");
    printf("6. Root\n");
    printf("Enter your choice (1-6): ");

    int choice;
    scanf("%d", &choice);
    printf("\n");
    
    main_board_upper();
    switch (choice) {
        case 1:
            printf("X + Y : %.2lf\n", x + y);
            break;
        case 2:
            printf("X - Y : %.2lf\n", x - y);
            break;
        case 3:
            printf("X x Y : %.2lf\n", x * y);
            break;
        case 4:
            if (y != 0) {
                printf("X / Y : %.2lf\n", x / y);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case 5:
            printf("X ^ Y : %.2lf\n", pow(x, y));
            break;
        case 6:
            printf("X root Y : %.2lf\n", pow(x, 1.0/y));
            break;
        default:
            printf("Invalid choice. Please select 1-6.\n");
    }
    main_board_lower();
    
}