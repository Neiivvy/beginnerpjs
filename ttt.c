#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//global variables
char board [3][3];
const char USER = 'X';
const char COMPUTER = 'O';

//function prototype or declaration
void gameboard();
void printboard();
int main()
{
    //this means that if winner is empty space then there is no winner
    //and if either one of the player wins there would be either x or o for the respective player
    char winner =' ';
    gameboard();
    printboard();


}
    void gameboard()    //for the structure of the 2d board or array
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j]= ' ';
            }
            
        }
        
    }

    void printboard()   // for format of how the board is printed 
    {   
        printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
       printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
       
        printf("\n");
    }

