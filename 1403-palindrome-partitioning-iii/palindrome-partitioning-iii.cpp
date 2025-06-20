class Solution {
public:
    int c(int i, int j, string& s) {
        int cnt = 0;
        while (i < j) {
            if (s[i++] != s[j--]) {
                cnt++;
            }
        }
        return cnt;
    }
    int f(int i, string& s, int k, int cnt, int n, vector<vector<int>>& dp) {
        if (i == n && cnt == k) {
            return 0;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int ans = 100000;
        for(int j=i; j<n; j++){
            ans = min(ans, c(i, j, s) + f(j+1, s, k, cnt+1, n, dp));
        }
        return dp[i][cnt] = ans;
    }
    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(0, s, k, 0, n, dp);
    }
};