#include <stdio.h>

int main(){
    FILE *fptr;
    char input[999];

    fptr = fopen("file.txt", "a");

    if(fptr == NULL){
        printf("\tFile doesn't exist\n\tCreating a new one!\n");
        fptr = fopen("file.txt", "w");

        printf("\tNow enter the content you want to add to the source file:\n");
        fgets(input, sizeof(input), stdin);
        fprintf(fptr, "%s", input);
    }else{
        printf("\tNow enter the content you want to add to the source file:\n");
        fgets(input, sizeof(input), stdin);
        fprintf(fptr, "%s", input);
    }

    fprintf(fptr, "\n\tThis lines should be added at the end of the previous lines.\n");
//The above line is just an extra. Not necessarily needed.
    fclose(fptr);

    return 0;
}