#include <stdio.h>

int main()
{
    int n, x;

    printf("How many elements do you want in the array? : ");
    scanf("%d", &n);

    printf("From where do you want to start? : ");
    scanf("%d", &x);

    int array[n], i;

    // Initialize the array with values starting from x
    for(i = 0; i < n; i++)
    {
        array[i] = x + i;  // Fill array with values starting from x
    }

    // Print the array with correct formatting
    printf("Array: {");
    for(i = 0; i < n; i++)
    {
        if(i == n - 1)  // Check if it's the last element
        {
            printf("%d", array[i]);  // Print last element without a comma
        }
        else
        {
            printf("%d, ", array[i]);  // Print element with a comma
        }
    }
    printf("}\n");

    return 0;
}
