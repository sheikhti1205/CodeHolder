#include <stdio.h>
int main(){
    FILE *fptr;

    char str[999];

    fptr = fopen("file.txt", "r");

    if(fptr == NULL){
        printf("\tFile doesn't exist\n\tcreating a new one!\n");
        fptr = fopen("file.txt", "w");

        if(fptr == NULL){
            printf("\tFile creation failed\nCould be permission issue\n");
            return 1;
        }
        /*
        char input[999];
        printf("\tNow enter the content you would like to add to the source file:\n");
        fgets(input, sizeof(input), stdin);
        fprintf(fptr, "%s", input);
        */
       fprintf(fptr, "This is an automated text since there was no source file.\n\tYou can delete these. No worries!\n");
       fclose(fptr);

       fptr = fopen("file.txt", "r");
       
       while(fgets(str, sizeof(str), fptr) != NULL){
        printf("%s", str);
       }
    }else{
        while(fgets(str, sizeof(str), fptr) != NULL){
            printf("%s", str);
        }
    }

    fclose(fptr);

    return 0;
}