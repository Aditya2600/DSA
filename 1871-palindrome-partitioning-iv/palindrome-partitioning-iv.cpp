class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();

        // Step 1: Precompute all palindromic substrings
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || isPal[i + 1][j - 1])) {
                    isPal[i][j] = true;
                }
            }
        }

        // Step 2: Bottom-up DP
        vector<vector<bool>> dp(n + 1, vector<bool>(4, false));
        dp[n][0] = true; // base case: 0 palindromic parts needed beyond end

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 3; k++) { // need to partition into k palindromic parts
                for (int j = i; j < n; j++) {
                    if (isPal[i][j] && dp[j + 1][k - 1]) {
                        dp[i][k] = true;
                        break; // no need to check further
                    }
                }
            }
        }

        return dp[0][3];
    }
};