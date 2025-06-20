class Solution {
public:
    // bool isPalindrome(int i, int j, string &s){
    //     while(i < j){
    //         if(s[i++] != s[j--]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    // bool f(int i, string &s, int n, int cnt, vector<vector<long long>>& dp){
    //     if(i == n){
    //         return cnt == 3;
    //     }
    //     if(dp[i][cnt] != -1) return dp[i][cnt];
    //     for(int j=i; j<n; j++){
    //         if(isPalindrome(i, j, s)){
    //             if(f(j+1, s, n, cnt+1, dp)){
    //                 return dp[i][cnt] = true;
    //             }
    //         }
    //     }
    //     return dp[i][cnt] = false;
    // }
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=0; i<n; i++){
            dp[i][i] = true;
            int l = i - 1;
            int r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                dp[l][r] = true;
                l--;
                r++;
            }
        }
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                int l = i-1;
                int r = i+2;
                while(l >= 0 && r < n && s[l] == s[r]){
                    dp[l][r] = true;
                    l--;
                    r++;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(dp[0][i]){
                for(int j=i+1; j<n-1; j++){
                    if(dp[i+1][j] && dp[j+1][n-1]){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};