#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int game(char player, char computer);
char getRandomChoice() 
{
    srand(time(NULL));
    int randomNum = rand() % 100;
    if (randomNum > 0 && randomNum <= 33)
        return 'S';
    else if (randomNum > 33 && randomNum <= 67)
        return 'P';
    else if (randomNum > 67 && randomNum <= 100)
        return 'R';
    else if (randomNum == 0)
        return 'R';
}

int main()
{
    
        char response;
    
    do
    {
    char playerChoice = 0;
    printf("Your Turn! [R (rock), P (paper), S (scissor)]  ::-- \n");
    scanf("%c", &playerChoice);
    playerChoice = toupper(playerChoice);

    
    char computerChoice = getRandomChoice();
    printf("Computer Chose: %c\n", computerChoice);

    int result = game(playerChoice, computerChoice);

    if(result == 0) {printf("You Win!\n");}
    else if(result == 1) {printf("You Lose!\n");}
    else if(result == -1) {printf("It's a tie!\n");}

    
    printf("\nWould you like to play again? (Y/N): ");
        scanf(" %c", &response);
        response = toupper(response);
        while (getchar() != '\n');
    } while (response == 'Y');

    printf("\nThanks for playing!\n");

    return 0;
}

int game(char player, char computer)
{
    const char rock = 'R';
    const char paper = 'P';
    const char scissor = 'S';

    if(player == computer) {return -1;} 
    else if((player == rock && computer == paper) || 
       (player == paper && computer == scissor) ||
       (player == scissor && computer == rock)) 
    {return 1;}
    else if((player == paper && computer == rock) || 
            (player == scissor && computer == paper) ||
            (player == rock && computer == scissor)) 
    {return 0;}
    else {printf("Wrong Input!\n Exiting...");}
}