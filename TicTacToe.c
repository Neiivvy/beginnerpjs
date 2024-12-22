#include<stdio.h>
#include<stdlib.h>
// #include<ctype.h>
// #include<time.h>

//global variables
char board [3][3];
const char USER1 = 'X';
const char USER2 = 'O';

//function prototype or declaration
void gameboard();
void printboard();
int freespace();
void player1move();
void boundarycheck();
void player2move();
char checkwinner();
void printwinner(char);

int main()
{
    //this means that if winner is empty space then there is no winner
    //and if either one of the player wins there would be either x or o for the respective player of their character
    char winner =' ';
    gameboard();

    freespace();
    //printing in while loop 
    while(winner==' ' && freespace() != 0)
    {

        printboard();
    //for player1
    player1move();
    winner=checkwinner();
    if(winner != ' ' || freespace() ==0)
    {
        break;
    }

    //for player2
      player2move();
    winner=checkwinner();
    if(winner != ' ' || freespace() ==0)
    {
        break;
    }


    }
    printboard();
    printwinner(winner);
    return 0;
}

//1. for the structure of the 2d board or array
    void gameboard() 
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j]= ' ';
            }
            
        }
        
    }
//2. for format of how the board is printed 
    void printboard()   
    {   
        printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
       printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
       
        printf("\n");
    }
//3.checking for the free space
    int freespace() 
    {
        int freespaces=9;    //no of spaces available for the moves since 3*3 so 9

        for(int i=0; i<3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if(board[i][j]!=' ')     //CHECK whether there are no free spaces on the current board that we are on
                {
                    freespaces--;    //then decrement the space by one
                }
            }
            
        }
        return freespaces; //here if it returns 0 then it means game over since there are no free spaces to move

    }
 //4.taking user input from first player
 void player1move()  
{
    int x, y;

    do
    {
        printf("Enter the row (1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter the column (1-3): ");
        scanf("%d", &y);
        y--;

        if (x < 0 || x > 2 || y < 0 || y > 2)
        {
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (board[x][y] != ' ')
        {
            printf("The space is occupied. Try again.\n");
        }
        else
        {
            board[x][y] = USER1;
            break;
        }
    } while (board[x][y]!=' ');
}

void player2move()
{
    int x, y;

    do
    {
        printf("Enter the row (1-3): ");
        scanf("%d", &x);
        x--;

        printf("Enter the column (1-3): ");
        scanf("%d", &y);
        y--;

        if (x < 0 || x > 2 || y < 0 || y > 2)
        {
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (board[x][y] != ' ')
        {
            printf("The space is occupied. Try again.\n");
        }
        else
        {
            board[x][y] = USER2;
            break;
        }
    } while (board[x][y]!=' ')  ;
}
void boundarycheck(){
    int x,y;
      if (x < 0 || x > 2 || y < 0 || y > 2)
        {
            printf("Invalid input. Try again.\n");
        }
}

//6.check the winner by checking (row, columns and diagonals condition)
char checkwinner()
{
    //for rows
    for (int i = 0; i < 3; i++)
    {
       if(board[i][0]==board[i][1] && board[i][1]==board[i][2])
       {
        return board[i][0];     //return winner
       }

    }
    
    

    //for columns
      
    for(int j = 0; j < 3; j++)
    {
       if(board[0][j]==board[1][j] && board[1][j]==board[2][j])
       {
        return board[0][j];     //return winner
       }
       
    
    
    }

    //for diagonals
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        return board[0][0];
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        return board[0][2];
    }
    return ' '; //if there is no winner

}

//7. this is for printing the winner if there is any
void printwinner(char winner){
    if(winner == USER1)
    {
        printf("User1 is the winner\n");
    }
    else if(winner == USER2){
        printf("user2 is the winner");
    }
    else{
        printf("It is a tie");
    }
}

