#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    const int MIN = 1;
    const int MAX = 100;
    int guess;
    int guesses = 0;
    int answer;

    //uses the current time as a seed
    srand(time(0));
    //generates a random number between MIN & MAX
    answer = (rand() % MAX) + MIN;

    do{
        printf("Enter a guess:\n");
        scanf("%d", &guess);
        if(guess > answer) {
            printf("Too HIGH!\n");
        }
        else if(guess < answer) {
            printf("Too Low!\n");
        }
        else{
            printf("CORRECT!\n");
        }
        guesses++;
    }while(guess != answer);
    
    printf("****************************************\n");
    printf("***ANSWER: %d***************************\n", answer);
    printf("***GUESSES it took  you!: %d*************\n", guesses);
    printf("****************************************\n");

    return 0;
}
