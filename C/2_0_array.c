#include <stdio.h>
int main()
{
    int marks[5] = {10, 12, 14, 16, 18};
    // the third bracket can be empty or a limit to the total number of
    // variable declared. In this case [5] 
    // To print value it starts like-
    // data_type array_name[limit] = {values with a "comma"  in between}
    // We will make a loop using for loop
    int i = 0;
    for(i = 0; i < 5; i++)
    {
        printf("Mark or roll %d is %d\n", i+1, marks[i]);
    }

    return 0;
}