class Solution {
    private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board) {
        int delrow[] = {+1, 0, -1, 0};
        int delcol[] = {0, +1, 0, -1};
        vis[row][col] = 1;  // Mark this cell as visited
        int n = board.size();
        int m = board[0].size();
        for (int d = 0; d < 4; d++) {
            int nrow = row + delrow[d];
            int ncol = col + delcol[d];
            // Check bounds and if the cell is unvisited and 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board);  // Corrected to use ncol instead of col
            }
        }
    }

    public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;  // Edge case: empty board
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Mark the boundary connected 'O's
        for (int j = 0; j < m; j++) {
            // Corrected condition to check if the cell is unvisited and 'O'
            if (vis[0][j] == 0 && board[0][j] == 'O') {
                dfs(0, j, vis, board);
            }
            if (vis[n-1][j] == 0 && board[n-1][j] == 'O') {
                dfs(n-1, j, vis, board);
            }
        }
        for (int i = 0; i < n; i++) {
            // Corrected condition to check if the cell is unvisited and 'O'
            if (vis[i][0] == 0 && board[i][0] == 'O') {
                dfs(i, 0, vis, board);
            }
            if (vis[i][m-1] == 0 && board[i][m-1] == 'O') {  // Corrected condition here
                dfs(i, m-1, vis, board);
            }
        }

        // Convert remaining 'O's to 'X' and visited '-' back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};