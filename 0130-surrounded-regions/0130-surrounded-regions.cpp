class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        
        queue<pair<int, int>> qu;
        
        // Mark boundary 'O's and push them into the queue
        for (int i = 0; i < n; ++i) {
            if (board[i][0] == 'O') {
                qu.push({i, 0});
                board[i][0] = '-';
            }
            if (board[i][m - 1] == 'O') {
                qu.push({i, m - 1});
                board[i][m - 1] = '-';
            }
        }
        for (int j = 0; j < m; ++j) {
            if (board[0][j] == 'O') {
                qu.push({0, j});
                board[0][j] = '-';
            }
            if (board[n - 1][j] == 'O') {
                qu.push({n - 1, j});
                board[n - 1][j] = '-';
            }
        }

        // Directions for moving up, right, down, left
        int nrow[] = {+1, 0, -1, 0};
        int ncol[] = {0, +1, 0, -1};

        // BFS to mark all connected 'O's starting from boundary 'O's
        while (!qu.empty()) {
            int row = qu.front().first;
            int col = qu.front().second;
            qu.pop();
            for (int k = 0; k < 4; ++k) {
                int newRow = row + nrow[k];
                int newCol = col + ncol[k];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && board[newRow][newCol] == 'O') {
                    qu.push({newRow, newCol});
                    board[newRow][newCol] = '-';
                }
            }
        }

        // Convert remaining 'O's to 'X' and '-' back to 'O'
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};