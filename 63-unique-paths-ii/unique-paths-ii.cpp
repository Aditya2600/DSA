class Solution {
public: 
    int dp[101][101];
    int f(int i, int j, vector<vector<int>>& obstacleGrid){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(dp[i][j] != -1) return dp[i][j];
        if(i == n-1 && j == m-1 && obstacleGrid[n-1][m-1] != 1) return 1;
        if(i < 0 || i >= n || j < 0 || j >= m) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        int ans = 0;
        ans = f(i+1, j, obstacleGrid) + f(i, j+1, obstacleGrid);
        return dp[i][j] = ans;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof dp);
        return f(0, 0, obstacleGrid);
    }
};