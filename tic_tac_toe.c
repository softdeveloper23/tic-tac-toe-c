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

// A function to take user input and validate the input
int get_move(char player, int *row, int *col)
{
    printf("Player %c, enter your move (row and column, 1-3): ", player);
    scanf("%d %d", row, col);

    // Validate the input
    if (*row < 1 || *row > 3 || *col < 1 || *col > 3)
    {
        printf("Invalid input. Please enter row and column numbers between 1 and 3.\n");
        return 0;
    }

    // Adjust indices to start from 0
    (*row)--;
    (*col)--;

    return 1;
}
