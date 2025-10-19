class Solution {
public:
    vector<vector<char>> board;
    vector<vector<string>> result;
    bool canPlaced(int r, int c, int n) {
        for (int i = r - 1; i >= 0; i--) {
            if (board[i][c] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = r - 1, j = c + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }

    void backTrack(int r, int n) {
        if(r == n){
            vector<string> temp;
            for(int i=0; i<n; i++){
                string res = "";
                for(int j=0; j<n; j++){
                    res += board[i][j];
                }
                temp.push_back(res);
            }
            result.push_back(temp);
        }
        for (int c = 0; c < n; c++) {
            if (canPlaced(r, c, n)) {
                board[r][c] = 'Q';
                backTrack(r + 1, n);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, vector<char> (n, '.'));
        backTrack(0, n);
        return result;
    }
};