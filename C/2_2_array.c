#include <stdio.h>
int main()
{
    int ft_marks[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100},
    st_marks[10];
    float total_marks[10];
    int i, j;

    for(i=0, j=9; i<10; i++, j--)
    {
        st_marks[j] = ft_marks[i];
    }

    printf("\n\nFirst Test Marks:  ");
    for(i=0; i<10; i++)
    {
        printf("%d ", ft_marks[i]);
    }
    
    printf("\n\nSecond Test Marks: ");
    for(i=0; i<10; i++)
    {
        printf("%d ", st_marks[i]);
    }

    for(i=0; i<10; i++)
    {
        total_marks[i] = ft_marks[i]/1.9 + st_marks[i]/2.7;
    }
    printf("\n\nTotal Marks:       ");
    for(i=0; i<10; i++)
    {
        printf("%.2lf ", total_marks[i]);
    }

    return 0;
}