#include <stdio.h>
#include <ctype.h>
int main() {
    char question[][100] = {"1. What year did the C language debut?: ",
                            "2. Who is credited with creating C?: ",
                            "3. What is the predecessor of C?: "};
    char options[][100] = {"A. 1969", "B. 1972", "C. 1975", "D. 1999",
                           "A. Dennis Ritchie", "B. Nicola Tesla", "C. John Carmack", "D. Doc Brown",
                           "A. Objectives", "B. B", "C. C++", "D. C#"};
    char answers[3] = {'B', 'A', 'B'};
    int numberofquestions = sizeof(question)/sizeof(question[0]);
    char guess;
    int score = 0;

    printf("QUIZ GAME\n");

    for(int i = 0; i <numberofquestions; i++) {
        printf("******************************************\n");
        printf("%s\n", question[i]);
        printf("******************************************\n");

        for(int j = (i * 4); j < (i * 4) + 4; j++) {
            printf("%s\n", options[j]);
        }

        printf("guess: ");
        scanf(" %c", &guess);
        //scanf(" %c"); //clear \n from input buffer

        guess = toupper(guess);

        if(guess == answers[i]) {
            printf("CORRECT!\n");
            score++;
        }
        else{
            printf("WRONG!\n");
        }
    }

    printf("*********************************\n");
    printf("FINAL SCORE: %d/%d\n", score, numberofquestions);
    printf("*********************************");

    return 0;
}