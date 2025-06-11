class Solution {
public:
    long long dp[101][101];
    // int f(int i, int j, vector<vector<int>>& obstacleGrid){
    //     int n = obstacleGrid.size();
    //     int m = obstacleGrid[0].size();
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(i == n-1 && j == m-1 && obstacleGrid[n-1][m-1] != 1) return 1;
    //     if(i < 0 || i >= n || j < 0 || j >= m) return 0;
    //     if(obstacleGrid[i][j] == 1) return 0;
    //     int ans = 0;
    //     ans = f(i+1, j, obstacleGrid) + f(i, j+1, obstacleGrid);
    //     return dp[i][j] = ans;

    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
            return 0;
        }

        memset(dp, 0, sizeof dp);
        dp[n - 1][m - 1] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; // obstacle cell
                } else {
                    if (i + 1 < n)
                        dp[i][j] += dp[i + 1][j];
                    if (j + 1 < m)
                        dp[i][j] += dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};