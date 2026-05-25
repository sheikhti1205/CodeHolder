#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

char board[9][9];
char PLAYER = 'X';
char COMPUTER = 'O';
int i = 0;
int j = 0;
int x = ' ';
int y = ' ';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main() {

    char winner = ' ';
    char response;

    do
    {
        winner = ' ';
        response = ' ';
        resetBoard();
    while(winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();

        printWinner(winner);

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            printWinner(winner);
            break;
        }
        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            printWinner(winner);
            break;
        }
    }

        printBoard();
        printWinner(winner);

        printf("\nWould You Like To Play Again?: ");
        scanf("%c", &response);
        //getchar();
        response = getchar();
        response = toupper(response);
    } while (response == 'Y');
   

    printf("\nThanks for playing!");

    /*

    resetBoard();

    while(winner == ' ' && checkFreeSpaces() != 0)
    {
        printBoard();

        playerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }

        computerMove();
        winner = checkWinner();
        if(winner != ' ' || checkFreeSpaces() == 0)
        {
            break;
        }
    }

    printBoard();
    printWinner(winner);
    */

    return 0;
}
void resetBoard()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7], board[2][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7], board[3][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7], board[4][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7], board[5][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7], board[6][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7], board[7][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    printf(" %c | %c | %c | %c | %c | %c | %c | %c | %c |", board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6], board[8][7], board[8][8]);
    printf("\n---|---|---|---|---|---|---|---|---|---\n");
    
    printf("\n");
}

int checkFreeSpaces()
{

    int freespaces = 81;

    for(i = 0; i < 9; i++)
    {
        for(j = 0; j < 9; j++)
        {
            if(board[i][j] !=' ')
            {
                freespaces--;
            }
        }
    }
    return freespaces;
}

void playerMove()
{
    do
    {
        printf("\nPLAYER __ 1\n");
        printf("Enter Row (value for x): \n");
        scanf("%d", &x);
        x--;
        printf("Enter Column (value for y): \n");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalid Move!\n");
        }
        else
        {
            board[x][y] = PLAYER;
            break;
        }
    }
    while(board[x][y] != ' ');
}

void computerMove()
{
    srand(time(0));
    int x;
    int y;

    if(checkFreeSpaces() > 0)
    {
        do
        {
            x = rand() % 9;
            y = rand() % 9;
        }
        while (board[x][y] != ' ');

        board[x][y] = COMPUTER;
        
    }
}

char checkWinner()
{
    for(i = 0; i < 9; i++)
    {
        //CHECK ROWS::
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] == board[i][3])
           {
            return board[i][0];
           }
        else if(board[i][1] == board[i][2] && board[i][1] == board[i][3] && board[i][1] == board[i][4])
           {
            return board[i][1];
           }
        else if(board[i][2] == board[i][3] && board[i][2] == board[i][4] && board[i][2] == board[i][5])
           {
            return board[i][2];
           }
        else if(board[i][3] == board[i][4] && board[i][3] == board[i][5] && board[i][3] == board[i][6])
           {
            return board[i][3];
           }
        else if(board[i][4] == board[i][5] && board[i][4] == board[i][6] && board[i][4] == board[i][7])
           {
            return board[i][4];
           }
        else if(board[i][5] == board[i][6] && board[i][5] == board[i][7] && board[i][5] == board[i][8])
        {
            return board[i][5];
        }
    }
    for(i = 0; i < 9; i++)
    {
        //CHECK COLUMNS::
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] == board[3][i])
           {
            return board[0][i];
           }
        else if(board[1][i] == board[2][i] && board[1][i] == board[3][i] && board[1][i] == board[4][i])
           {
            return board[1][i];
           }
        else if(board[2][i] == board[3][i] && board[2][i] == board[4][i] && board[2][i] == board[5][i])
           {
            return board[2][i];
           }
        else if(board[3][i] == board[4][i] && board[3][i] == board[5][i] && board[3][i] == board[6][i])
           {
            return board[3][i];
           }
        else if(board[4][i] == board[5][i] && board[4][i] == board[6][i] && board[4][i] == board[7][i])
           {
            return board[4][i];
           }
        else if(board[5][i] == board[6][i] && board[5][i] == board[7][i] && board[5][i] == board[8][i])
           {
            return board[5][i];
           }
    }   
    //}
    //CHECK DIAGNALS 1::
        if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == board[3][3])
           {
            return board[0][0];
           }
        else if(board[1][1] == board[2][2] && board[1][1] == board[3][3] && board[1][1] == board[4][4])
           {
            return board[1][1];
           }
        else if(board[2][2] == board[3][3] && board[2][2] == board[4][4] && board[2][2] == board[5][5])
           {
            return board[2][2];
           }
        else if(board[3][3] == board[4][4] && board[3][3] == board[5][5] && board[3][3] == board[6][6])
           {
            return board[3][3];
           }
        else if(board[4][4] == board[5][5] && board[4][4] == board[6][6] && board[4][4] == board[7][7])
           {
            return board[4][4];
           }
        else if(board[5][5] == board[6][6] && board[5][5] == board[7][7] && board[5][5] == board[8][8])
           {
            return board[5][5];
           }
    //CHECK DIAGNALS 2::
        if(board[0][8] == board[1][7] && board[0][8] == board[2][6] && board[0][8] == board[3][5])
           {
            return board[0][8];
           }
        else if(board[1][7] == board[2][6] && board[1][7] == board[3][5] && board[1][7] == board[4][4])
           {
            return board[1][7];
           }
        else if(board[2][6] == board[3][5] && board[2][6] == board[4][4] && board[2][6] == board[5][3])
            {
            return board[2][6];
            }
        else if(board[3][5] == board[4][4] && board[3][5] == board[5][3] && board[3][5] == board[6][2])
            {
            return board[3][5];
            }
        else if(board[4][4] == board[5][3] && board[4][4] == board[6][2] && board[4][4] == board[7][1])
            {
            return board[4][4];
            }
        else if(board[5][3] == board[6][2] && board[5][3] == board[7][1] && board[5][3] == board[8][0])
            {
            return board[5][3];
            }
    
    //return ' ';
}

void printWinner(char winner)
    {
        if(winner == PLAYER)
        {
            printf("PLAYER WINS!\n");
        }
        else if(winner == COMPUTER)
        {
            printf("COMPUTER WINS!\n");
        }
/*        else if(PLAYER1 == PLAYER2)
        {
            printf("IT'S A TIE!\n");
        }
        else
        {
            printf("NEXT! IS!\n");
        }
*/
    }

