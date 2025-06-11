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
        memset(dp, 0, sizeof(dp));
        int n = grid.size();
        int m = grid[0].size();
        
        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1){
                    dp[n-1][m-1] = grid[n-1][m-1];
                }
                else{
                    int right = (j + 1 < m) ? dp[i][j+1] : INT_MAX;
                    int down = (i + 1 < n) ? dp[i+1][j] : INT_MAX;
                    dp[i][j] = grid[i][j] + min(right, down);
                }                                                             
            }
        }
        return dp[0][0];
    }
};