#include <stdio.h>
int main() {
    
    FILE *pF = fopen("test.txt", "a"); //w = write, a = append

    //test.txt = any path like C:\\user\\0\\.... absolute path

    fprintf(pF, "\nSpongeBob SquarePants");

    fclose(pF);
    
    /*
   if(remove("test.txt") == 0) {
    printf("That file was removed successfully!");
   }
   else {
    printf("Failed to remove test.txt!");
   }
   */
}