
#include <iostream>
#include <vector>

using namespace std;

// Function to draw the tic-tac-toe board
void drawBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " " << endl;
        if (i != 2) {
            cout << "-----------" << endl;
        }
    }
}

// Function to check if the game is over
bool isGameOver(const vector<vector<char>>& board) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')) {
        return true;
    }

    // Check if the board is full
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }

    return true;
}

// Function to check if a move is valid
bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to make a move
void makeMove(vector<vector<char>>& board, int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    int row, col;
    char currentPlayer = 'X';

    while (!isGameOver(board)) {
        // Draw the board
        drawBoard(board);

        // Get the current player's move
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        if (isValidMove(board, row, col)) {
            // Make the move
            makeMove(board, row, col, currentPlayer);

            // Switch to the other player
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }

    // Draw the final board
    drawBoard(board);

    // Check the winner
    if (isGameOver(board)) {
        cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!" << endl;
    } 
    else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
