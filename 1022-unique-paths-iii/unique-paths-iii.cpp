class Solution {
public:
    int result = 0;

    void dfs(vector<vector<int>>& grid, int row, int col, int cnt) {
        int n = grid.size();
        int m = grid[0].size();
        if (row >= n || row < 0 || col >= m || col < 0 ||
            grid[row][col] == -1)
            return;
        if (grid[row][col] == 2 && cnt == 0) {
            result++;
            return;
        }
        int temp = grid[row][col];
        grid[row][col] = -1;
        dfs(grid, row + 1, col, cnt-1);
        dfs(grid, row - 1, col, cnt-1);
        dfs(grid, row, col + 1, cnt-1);
        dfs(grid, row, col - 1, cnt-1);
        grid[row][col] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 1;
        int row = 0;
        int col = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                }
                if (grid[i][j] == 1) {
                    row = i;
                    col = j;
                }
            }
        }
        dfs(grid, row, col, cnt);
        return result;
    }
};