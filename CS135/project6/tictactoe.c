//Name: Joshua Insorio 
//Date: 2/28/17
//project 6: tictactoe_c.c
//Function: Create tic-tac-toe

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3


int clear_table(char board[SIZE][SIZE]);
int display_table(char board[SIZE][SIZE]);
int check_legal_option(char board[SIZE][SIZE], int row, int col);
int update_table(char board[SIZE][SIZE], int row, int col, char move);
int get_player1_move(char board[SIZE][SIZE], int row, int col);
int generate_player2_move(char board[SIZE][SIZE], int row, int col);
int check_three_in_a_row(char board[SIZE][SIZE]);
int check_table_full(char board[SIZE][SIZE]);
int check_end_of_game(char board[SIZE][SIZE]);
int print_winner(char board[SIZE][SIZE]);

int main (void)
{
 //Declare the tic-tac-toe board
 char board[SIZE][SIZE];
 //The row and column of the move for either player 1 or 2
 int row, col;
 //Clear the table
clear_table(board);
 //Display the table
display_table(board);



 do
    {
    //Have player 1 enter their move
    get_player1_move(board, row, col);
    //Generate player 2 move
    generate_player2_move(board, row, col);
    //Do this while the game hasn't ended
    }while(check_end_of_game(board) == false);

 //After the game is over, print who won
 print_winner(board);




 return 0;
}

int clear_table(char board[SIZE][SIZE])
{
    for(int row = 0; row < SIZE ; row++)
    {
        for(int col = 0; col < SIZE ; col++)
        {
            board[row][col] = '\0';
        }
    }

    return 0;
}

int display_table(char board[SIZE][SIZE])
{
    printf("The current state of the game is: \n");
    for(int row = 0; row < SIZE ; row++)
    {
        for(int col = 0; col < SIZE ; col++)
        {
            if(board[row][col] == '\0')
            {
                printf("_ ");
            }
            else
            {
                printf("%c ", board[row][col]);
            }
        }
        printf("\n");
    }

    return 0;
}

int check_legal_option(char board[SIZE][SIZE], int row, int col)
{
    int legal;
    if((row < 3 && col < 3) && (check_table_full(board) == false))
    {
        if(board[row][col] == '\0')
        {
            legal = true;
        }
        else
        {
            legal = false;
        }
    }
    else
    {
        legal = false;
    }

    return legal;
}

int update_table(char board[SIZE][SIZE], int row, int col, char move)
{
    board[row][col] = move;
    return 0;
}

int get_player1_move(char board[SIZE][SIZE], int row, int col)
{
    do
    {
    printf("Player 1 enter your selection [row, col]: ");
    scanf("%d, %d", &row, &col);
    row -= 1;
    col -= 1;
    }while(check_legal_option(board, row, col) == false);

    update_table(board, row, col, 'O');
    display_table(board);
    
    return 0;
}

int generate_player2_move(char board[SIZE][SIZE], int row, int col)
{

    srand(time(NULL));
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    }while((check_legal_option(board, row, col) == false) && (check_end_of_game(board) == false));

    update_table(board, row, col, 'X');
    printf("Player 2 has entered [row, col]: %d, %d\n", row + 1, col + 1);
    display_table(board);

    return 0;
}

int check_table_full(char board[SIZE][SIZE])
{
    int counter = 0, full;
    for(int row = 0; row < SIZE ; row++)
    {
        for(int col = 0; col < SIZE ; col++)
        {
            if(board[row][col] != '\0')
            {
                counter += 1;
            }
        }
    }

    if(counter == 9)
    {
        full = true;

    }
    else
    {
        full = false;
    }

    return full;
}

int check_three_in_a_row(char board[SIZE][SIZE])
{

    if(
    (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') || 
    (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
    (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
    (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
    (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
    (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
    (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
    (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
    {
        return 1;
    }

    else if( 
    (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
    (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
    (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
    (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
    (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
    (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
    (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
    (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
    {
        return 2;
    }

    else
    {
        return 0;
    }

}

int check_end_of_game(char board[SIZE][SIZE])
{
    int result;
    if((check_three_in_a_row(board) == 1) || (check_three_in_a_row(board) == 2) || (check_table_full(board) == true))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int print_winner(char board[SIZE][SIZE])
{
    if((check_end_of_game(board) == true) || check_table_full(board) == true)
    {
        if((check_three_in_a_row(board) == 1))
        {
            printf("Congratulations, Player %d wins!\n", check_three_in_a_row(board));
            return 0;
        }

        else if((check_three_in_a_row(board) == 2))
        {
            printf("Congratulations, Player %d wins!\n", check_three_in_a_row(board));
            return 0;
        }

        else
        {
            printf("Game over, no player wins.\n");
            return 0;
        }
    }
    return 0;
}