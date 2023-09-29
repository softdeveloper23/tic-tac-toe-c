#include <stdio.h>

// Tic, Tac, Toe

int main()
{
    // 3x3 array
    char board[3][3] = {
        {' ', ' ', ' '}, // row 0
        {' ', ' ', ' '}, // row 1
        {' ', ' ', ' '}  // row 2
    };

    // Display the board
    display_board(board);
}

// A function to display the current state of the game board
void display_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; i < 3; j++)
        {
            printf("%c", board[i][j]);
            if (j < 2)
            {
                printf("| ");
            }
        }
        if (i < 2)
        {
            printf("\n---------\n");
        }
    }
    printf("\n");
}
