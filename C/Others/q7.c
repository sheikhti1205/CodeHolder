#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *input = fopen("bookData.txt", "r");
    if(!input){
        printf("Failed to open file!\n");
        return 1;
    }

    char line[100], course[100], maxCourse[100];
    int count, maxCount = 0;

    while(fgets(line, sizeof(line), input)){
        sscanf(line, "%[^-]-%d", course, &count);
        if(count > maxCount){
            maxCount = count;
            strcpy(maxCourse, course);
        }
    } fclose(input);
    
    FILE *output = fopen("max.txt", "w");
    fprintf(output, "%s-%d\n", maxCourse, maxCount);
    fclose(output);

    printf("Course with max books, %s - %d\n", maxCourse, maxCount);

    return 0;
}