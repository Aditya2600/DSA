class Solution {
public:

    /*vector<vector<int>> arr,dp;
    int n,m;
    int f(int i, int j){
        if(i == n-1 && j == m-1) return arr[n-1][m-1];
        if(i >= n || i < 0 || j >= m || j < 0) return INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = arr[i][j] + min(f(i+1,j), f(i,j+1));
    }*/
    int minPathSum(vector<vector<int>>& grid) {
        /*arr = grid;
         n = arr.size();
         m = arr[0].size();
        dp.clear();
        dp.resize(200,vector<int> (200,-1));
        return f(0,0);*/
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int> (m,0));
        dp[0][0] = grid[0][0];
        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int j=1; j<m; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + grid[i][j];
            }
        }
        return dp[n-1][m-1];
    }
};