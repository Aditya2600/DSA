class Solution {
public:
    int dp[200][200];
    int f(int i, int j, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i >= n || j >= m) return INT_MAX;
        if(i == n-1 && j == m-1) return grid[i][j];
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = grid[i][j] + min(f(i+1, j, grid), f(i, j+1, grid));
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return f(0, 0, grid);
    }
};