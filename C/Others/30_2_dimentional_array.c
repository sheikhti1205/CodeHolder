#include <stdio.h>
int main() {
    /*2 Dimentional or 2D arrays = an array, where 
    each element is an entire array useful if you need a matrix, grid or a table of data*/

    
    int num[3][3] = {
                     {1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}
                     };
    

   //int num[3][3];

   int row = sizeof(num)/sizeof(num[0]);
   int col = sizeof(num[0])/sizeof(num[0][0]);

/*
   num[0][0] = 1;
   num[0][1] = 2;
   num[0][2] = 3;
   num[1][0] = 4;
   num[1][1] = 5;
   num[1][2] = 6;
   num[2][0] = 7;
   num[2][1] = 8;
   num[2][2] = 9;
*/

   for(int i = 0; i < row; i++) 
   {
    for(int j = 0; j < col; j++) 
    {
        printf("%d ", num[i][j]);
    }
    printf("\n");
   }

   return 0; 
}