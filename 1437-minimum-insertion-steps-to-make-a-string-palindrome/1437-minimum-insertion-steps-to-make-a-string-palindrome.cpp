class Solution {
public:
    int all_longest_common_subsequences_length(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(s[i] == t[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return all_longest_common_subsequences_length(s, t);
    }
    int minInsertions(string s) {
        int n = s.length();
        return n - longestPalindromeSubseq(s);
    }
};