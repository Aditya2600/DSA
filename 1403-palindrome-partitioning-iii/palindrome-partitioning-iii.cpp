class Solution {
public:
    int c(int i, int j, const string &s) {
        int cnt = 0;
        while (i < j) {
            if (s[i] != s[j]) {
                cnt++;
            }
            i++;
            j--;
        }
        return cnt;
    }

    int f(int i, int cnt, int n, int k, const string &s, vector<vector<int>> &dp) {
        if (i == n) {
            if (cnt == k) {
                return 0;
            } else {
                return 100000;
            }
        }
        if (dp[i][cnt] != -1) {
            return dp[i][cnt];
        }
        int ans = 100000;
        for (int j = i; j < n; j++) {
            ans = min(ans, c(i, j, s) + f(j + 1, cnt + 1, n, k, s, dp));
        }
        return dp[i][cnt] = ans;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(0, 0, n, k, s, dp);
    }
};