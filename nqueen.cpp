#include <iostream>
#include <vector>

using namespace std;

void printBoard(const vector<vector<int> >& board) {
    int N = board.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(const vector<vector<int> >& board, int row, int col) {
    int N = board.size();

    // Check if any queen is present in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if any queen is present in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if any queen is present in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void solveNQueens(vector<vector<int> >& board, int row) {
    int N = board.size();

    // Base case: all queens have been placed
    if (row == N) {
        printBoard(board);
        return;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place the queen

            // Recursively solve the problem for the next row
            solveNQueens(board, row + 1);

            board[row][col] = 0;  // Remove the queen (backtracking)
        }
    }
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N): ";
    cin >> N;

    vector<vector<int> > board(N, vector<int>(N, 0));

    solveNQueens(board, 0);

    return 0;
}
