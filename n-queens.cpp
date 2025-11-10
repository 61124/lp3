#include <iostream>
using namespace std;

#define N 8
int board[N][N];
int solutionCount = 0;

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

void solve(int row) {
    if(row == N) {
        solutionCount++;
        cout << "\nSolution " << solutionCount << ":\n\n";
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        return; // Continue searching for more solutions
    }

    for(int col = 0; col < N; col++) {
        if(isSafe(row, col)) {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0; // backtrack
        }
    }
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

    // Solve remaining queens
    solve(1);

    if(solutionCount == 0)
        cout << "\nNo solution possible with first queen at column " << col << endl;
    else
        cout << "\nTotal solutions found: " << solutionCount << endl;

    return 0;
}
