#include <iostream>
#include <vector>
using namespace std;

bool isSafe(const vector<vector<int>>& board, int row, int col, int n) {
    // Check left side of this row
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) return false;
    }
    // Check upper diagonal (top-left)
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    // Check lower diagonal (bottom-left)
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) return false;
    }
    return true;
}

// Updated function to count solutions
void solveNQueens(vector<vector<int>>& board, int col, int n, int &count) {
    if (col >= n) { // Base case: all queens are placed
        count++; // increment solution count
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i][j] == 1 ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;
            solveNQueens(board, col + 1, n, count);
            board[i][col] = 0; // Backtrack
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the board: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));
    int count = 0;

    solveNQueens(board, 0, n, count);

    cout << "Total number of solutions: " << count << endl;

    return 0;
}
