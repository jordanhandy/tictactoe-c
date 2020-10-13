/* Tic Tac Toe game written in C.
* Author: Jordan Handy
* Date: October, 2020
*
* Functions:
* drawBoard - draw the game board
* markBoard - mark the game board on a player move
* checkForWin - check for a winner at each move
*
*/

// libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// declare
// An array that represents the game board
char gameBoard[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char playerMove; // represents the players move "'X' or 'O'"
int player; // The player counter, either player 1 or player 2
int playerWin = -1; // game end flag.  If winner > 0

// declare functions
void drawBoard(); 
void markBoard(char mark);
int checkForWin();

int main()
{
    char mark; // 'X' or 'O' mark to be passed to markBoard() function
    player = 1; // initialize to player 1
    printf("\tTic Tac Toe\t\t\n");
    printf("Player 1 is (X), Player 2 is (O)\n\n");
    drawBoard(); // draw the game board
    while (playerWin < 0)
    // if the playerWin variable is either 0, 1, or 2, that equals a draw, or victory for 
    // the corresponding player respectively
    {
        // Game Start
        
        // Ternary:  if the value of Player % 2 is even or odd, the opposite player is chosen
        player = (player % 2) ? 1 : 2;
        printf("\nPlayer %d, select a location: ",player);
        scanf("%d", &playerMove); // take the player's choice
        // use same mod function to determine X or O
        mark = (player % 2) ? 'X' : 'O';
        // pass to markBoard
        markBoard(mark);
        playerWin = checkForWin();
        player++; // increment player
        drawBoard(); // redraw board
    }

    // victory for corresponding player
    if (playerWin >= 0)
    {
        printf("The game is over!  Player %d Wins!", playerWin);
    }
    else
    {
        printf("The game has ended in a draw!");
    }

    return 0;
}

// draw the game board with the values in the global gameBoard array
void drawBoard()
{
    system("clear"); // clear the screen
    printf("       |        |         \n");
    printf("   %c   |   %c    |    %c    \n", gameBoard[1], gameBoard[2], gameBoard[3]);
    printf("_______|________|_________\n");
    printf("       |        |         \n");
    printf("   %c   |   %c    |    %c    \n", gameBoard[4], gameBoard[5], gameBoard[6]);
    printf("       |        |         \n");
    printf("-------|--------|---------\n");
    printf("   %c   |   %c    |    %c    \n", gameBoard[7], gameBoard[8], gameBoard[9]);
    printf("       |        |         \n");
}

void markBoard(char move)
{
    // Mark the board.  If the value in the array corresponding to the player's choice
    // still has the initial value in it, then mark
    if (playerMove == 1 && gameBoard[1] == '1')
    {
        gameBoard[1] = move;
    }

    else if (playerMove == 2 && gameBoard[2] == '2')
    {
        gameBoard[2] = move;
    }
    else if (playerMove == 3 && gameBoard[3] == '3')
    {
        gameBoard[3] = move;
    }
    else if (playerMove == 4 && gameBoard[4] == '4')
    {
        gameBoard[4] = move;
    }
    else if (playerMove == 5 && gameBoard[5] == '5')
    {
        gameBoard[5] = move;
    }
    else if (playerMove == 6 && gameBoard[6] == '6')
    {
        gameBoard[6] = move;
    }
    else if (playerMove == 7 && gameBoard[7] == '7')
    {
        gameBoard[7] = move;
    }
    else if (playerMove == 8 && gameBoard[8] == '8')
    {
        gameBoard[8] = move;
    }
    else if (playerMove == 9 && gameBoard[9] == '9')
    {
        gameBoard[9] = move;
    }
    else
    {
        // otherwise, the choice is invalid.
        printf("Sorry, this move is invalid\nPress enter to try again");
        player--;
        getchar();
    }
    
}

int checkForWin()
{
    // The player wins if they match the standard "Tic Tac Toe" victory patterns
    // The playerWin variable is then set to the corresponding winner, according
    // to the marks that match
    int playerWin = -1;
    if (gameBoard[1] == 'X' && gameBoard[2] == 'X' && gameBoard[3] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[4] == 'X' && gameBoard[5] == 'X' && gameBoard[6] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[7] == 'X' && gameBoard[8] == 'X' && gameBoard[9] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[1] == 'X' && gameBoard[4] == 'X' && gameBoard[7] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[2] == 'X' && gameBoard[5] == 'X' && gameBoard[8] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[3] == 'X' && gameBoard[6] == 'X' && gameBoard[9] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[1] == 'X' && gameBoard[5] == 'X' && gameBoard[9] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[3] == 'X' && gameBoard[5] == 'X' && gameBoard[7] == 'X')
    {
        playerWin = 1;
    }
    else if (gameBoard[1] == 'O' && gameBoard[2] == 'O' && gameBoard[3] == 'O')
    {
        playerWin = 2;
    }
    else if (gameBoard[4] == 'O' && gameBoard[5] == 'O' && gameBoard[6] == 'O')
    {
        playerWin = 2;
    }
    else if (gameBoard[7] == 'O' && gameBoard[8] == 'O' && gameBoard[9] == 'O')
    {
        playerWin = 2;
    }
    else if (gameBoard[1] == 'O' && gameBoard[4] == 'O' && gameBoard[7] == 'O')
    {
        playerWin = 2;
    }
    else if (gameBoard[2] == 'O' && gameBoard[5] == 'O' && gameBoard[8] == 'O')
    {
        playerWin = 2;
    }
    else if (gameBoard[3] == 'O' && gameBoard[6] == 'O' && gameBoard[9] == 'O')
    {
        playerWin = 2;
    }
    else if (gameBoard[1] == 'O' && gameBoard[5] == 'O' && gameBoard[9] == 'O')
    {
        playerWin = 2;
    }
    else if (gameBoard[3] == 'O' && gameBoard[5] == 'O' && gameBoard[7] == 'O')
    {
        playerWin = 2;
    }
    // if none of the values are still their original, the game ends in a draw
    else if (gameBoard[1] != '1' && gameBoard[2] != '2' && gameBoard[3] != '3' && gameBoard[4] != '4' 
            && gameBoard[5] != '5' && gameBoard[6] != '6' && gameBoard[7] != '7' && gameBoard[8] != '8'
            && gameBoard[9] != '9')
    {
        playerWin = 0;
    }
    else
    {
        // otherwise, the game continues
        playerWin = -1;
    }
    return playerWin;
}