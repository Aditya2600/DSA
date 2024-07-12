class Solution {
public:
    int uniquePathsHelper(int i, int j, int m, int n, vector<vector<int>> &dp) {
        if (i >= n || j >= m) return 0; // Out of bounds
        if (i == n-1 && j == m-1) return 1; // Reached the destination
        if (dp[i][j] != -1) return dp[i][j]; // Memoized result
        dp[i][j] = uniquePathsHelper(i + 1, j, m, n, dp) + uniquePathsHelper(i, j + 1, m, n, dp); // Calculate and memoize
        return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table initialized with -1
        return uniquePathsHelper(0, 0, m, n, dp); // Start from the top-left corner
    }
};
