class Solution {
public:
    // This function implements the regex matching using DP
    bool isMatch(string s, string p) {
        int m = s.size(); // Length of input string
        int n = p.size(); // Length of pattern string
        
        // dp[i][j] means whether s[0...i-1] matches p[0...j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Initialize: empty pattern matches empty string.
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c* etc.
        for (int j = 2; j <= n; j++) {
            // If the current char in pattern is '*' and pattern up to two characters before matches empty string,
            // then pattern up to j characters matches an empty string.
            if (p[j - 1] == '*' && dp[0][j - 2]) {
                dp[0][j] = true;
            }
        }
        
        // Fill table in bottom up manner.
        // Loop through each character in input string.
        for (int i = 1; i <= m; i++) {
            // Loop through each character in pattern.
            for (int j = 1; j <= n; j++) {
                // If the current character in pattern is not a '*'
                if (p[j - 1] != '*') {
                    // It matches if previous characters match and current characters match (or pattern char is '.')
                    if (dp[i - 1][j - 1] && (p[j - 1] == s[i - 1] || p[j - 1] == '.')) {
                        dp[i][j] = true;
                    }
                } else {
                    // If p[j-1] is '*' we have two conditions to check.
                    // 1) '*' stands for 0 occurrences of the element before '*'.
                    if (dp[i][j - 2]) {
                        dp[i][j] = true;
                    }
                    // 2) '*' stands for at least one occurrence if preceding element matches the string.
                    // Check if the preceding element in pattern matches the current character in string or is '.'
                    if (i > 0 && dp[i - 1][j] && (p[j - 2] == s[i - 1] || p[j - 2] == '.')) {
                        dp[i][j] = true;
                    }
                }
            }
        }
        // Return whether the entire string s matches the entire pattern p.
        return dp[m][n];
    }
};