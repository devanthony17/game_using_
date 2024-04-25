
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    // Function to display the Tic Tac Toe board
void displayBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
}

// Function to check if the current player wins
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}

// Function to check if the board is full
bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;

    cout << "Welcome to Tic Tac Toe!\n";

    while (true) {
        cout << "Player " << currentPlayer << "'s turn. Enter row (0-2) and column (0-2) separated by a space: ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Display the board
        displayBoard(board);

        // Check if the current player wins
        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check if it's a draw
        if (checkDraw(board)) {
            cout << "It's a draw!\n";
            break;
        }
        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}

