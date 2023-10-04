#include <stdio.h>

void display_board(char board[3][3]);
int get_move(char player, int *row, int *col);
int update_board(char board[3][3], int row, int col, char player);
char check_winner(char board[3][3]);
char switch_player(char player);

// Tic, Tac, Toe

int main()
{
    // 3x3 array
    char board[3][3] = {
        {' ', ' ', ' '}, // row 0
        {' ', ' ', ' '}, // row 1
        {' ', ' ', ' '}  // row 2
    };

    char player = 'X';
    int moves = 0;
    int row, col;
    char winner = ' ';

    // While loop to keep the game going until there is a winner or the board is full
    while (winner == ' ' && moves < 9)
    {
        display_board(board);

        int valid_move = 0;
        while (!valid_move)
        {
            valid_move = get_move(player, &row, &col) && update_board(board, row, col, player);
        }

        winner = check_winner(board);
        player = switch_player(player);
        moves++;
    }

    // Display the board
    display_board(board);

    // Display the winner
    if (winner != ' ')
    {
        printf("Player %c wins!\n", switch_player(player));
    }
    else
    {
        printf("It's a draw!\n");
    }
}

// A function to display the current state of the game board
void display_board(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
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

// Udpate the board with the player's move
int update_board(char board[3][3], int row, int col, char player)
{
    if (board[row][col] == ' ')
    {
        board[row][col] = player;
        return 1;
    }
    else
    {
        printf("Cell already occupied. Choose another cell.\n");
        return 0;
    }
}

// Check for a winner
char check_winner(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        // Check horizontal and vertical lines
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') ||
            (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' '))
        {
            return board[i][i];
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
    {
        return board[1][1];
    }

    return ' ';
}

// Switch player
char switch_player(char player)
{
    return (player == 'X') ? 'O' : 'X';
}
