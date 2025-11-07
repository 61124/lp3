#include <iostream>
using namespace std;

#define N 8
int board[N][N];

bool isSafe(int row, int col) {
    int i, j;

    // Check column
    for(i = 0; i < row; i++)
        if(board[i][col] == 1)
            return false;

    // Check upper left diagonal
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if(board[i][j] == 1)
            return false;

    // Check upper right diagonal
    for(i = row, j = col; i >= 0 && j < N; i--, j++)
        if(board[i][j] == 1)
            return false;

    return true;
}

bool solve(int row) {
    if(row == N) // all queens placed
        return true;

    for(int col = 0; col < N; col++) {
        if(isSafe(row, col)) {
            board[row][col] = 1;

            if(solve(row + 1))
                return true;

            board[row][col] = 0; // backtrack
        }
    }
    return false;
}

int main() {
    // Initialize board with 0
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            board[i][j] = 0;

    int col;
    cout << "Enter column position (0-7) for the first Queen in row 0: ";
    cin >> col;

    // Validate input
    if(col < 0 || col >= N) {
        cout << "Invalid column input!" << endl;
        return 0;
    }

    // Place the first queen
    board[0][col] = 1;

    // Try to solve remaining queens
    if(solve(1)) {
        cout << "\nSolution Found:\n\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
    } else {
        cout << "\nNo solution possible with first queen at column " << col << endl;
    }

    return 0;
}