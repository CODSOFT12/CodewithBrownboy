#include <iostream>
using namespace std;
void displayBoard(char board[3][3]) 
{
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 3; ++col) 
        {
            cout << board[row][col];
            if (col < 2) cout << " | ";
        }
        cout << endl;
        if (row < 2) cout << "---------" << endl;
    }
}

bool checkWin(char board[3][3], char player) 
{
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; 
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; 
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; 
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') return false;
        }
    }
    return true;
}

int main()
{
    char board[3][3] = { { ' ', ' ', ' ' }, { ' ', ' ', ' ' }, { ' ', ' ', ' ' } };
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player 1: X | Player 2: O" << endl;

    while (!gameWon && !gameDraw) {
        displayBoard(board);
        int row, col;

     
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

    
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;

            
            if (checkWin(board, currentPlayer)) 
            {
                gameWon = true;
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!" << endl;
            }
            else 
            {
               
                if (checkDraw(board)) {
                    gameDraw = true;
                    displayBoard(board);
                    cout << "It's a draw! The game is over." << endl;
                }
                else 
                {
                   
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
        }
        else
        {
            cout << "Invalid move. Try again." << endl;
        }
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;
    return 0;
}
