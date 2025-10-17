class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    // int f(int ind, string& s, vector<int>& dp) {
    //     int n = s.size();
    //     if (ind == n) {
    //         return 0;
    //     }
    //     if(dp[ind] != -1) return dp[ind];
    //     int ans = 1e9;
    //     for (int i = ind; i < n; i++) {
    //         if (isPalindrome(s, ind, i)) {
    //             int cut = (i == n-1) ? 0 : 1 + f(i + 1, s, dp);
    //             ans = min(ans, cut);
    //         }
    //     }

    //     return dp[ind] = ans;
    // }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        dp[n-1] = 0;
        for (int ind = n - 1; ind >= 0; ind--) {
            int ans = 1e9;
            for (int i = ind; i < n; i++) {
                if (isPalindrome(s, ind, i)) {
                    int cut = (i == n - 1) ? 0 : 1 + dp[i + 1];
                    ans = min(ans, cut);
                }
            }
            dp[ind] = ans;
        }

        return dp[0] - 1;
    }
};