class Solution {
public:
    bool dfs(int i, int j, int from_i, int from_j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        int delRow[] = {+1, 0, -1, 0};
        int delCol[] = {0, +1, 0, -1};
        vis[i][j] = 1;
        for (int d = 0; d < 4; d++) {
            int newRow = i + delRow[d];
            int newCol = j + delCol[d];
            if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m && grid[newRow][newCol] == grid[i][j]) {
                if (vis[newRow][newCol] == 0) {
                    if (dfs(newRow, newCol, i, j, grid, vis)) {
                        return true;
                    }
                } else if (newRow != from_i || newCol != from_j) {
                    return true;
                }
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
