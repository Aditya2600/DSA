// class Solution {
// public:
//     int f(int i, int j, int m, int n, vector<vector<int>>& dp) {
//         if (i == m - 1 && j == n - 1) {
//             return 1;
//         }
//         if(dp[i][j] != -1) return dp[i][j];
//         if(i >= m || j >= n) return 0;
//         dp[i][j] = f(i + 1, j, m, n, dp) + f(i, j + 1, m, n, dp);
//         return dp[i][j];
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1, vector<int> (n+1, -1));
//         return f(0, 0, m, n, dp);
//     }
// };
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
                }
            }
        }
        return dp[0][0];
    }
};