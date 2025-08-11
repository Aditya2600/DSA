// class Solution {
// private:
//     bool isPalindrome(const string &s){
//         int l = 0;
//         int r = s.length() - 1;
//         while(l < r){
//             if(s[l] != s[r]){
//                 return false;
//             }
//             l++;
//             r--;
//         }
//         return true;
//     }
// public:
//     string longestPalindrome(string s) {
//         if(s.length() <= 1){
//             return s;
//         }
//         int max_len = 1;
//         string max_str = s.substr(0, 1);
//         for(int i=0; i<s.length(); i++){
//             for(int j=i+max_len; j<=s.length(); j++){
//                 if(j-i > max_len && isPalindrome(s.substr(i, j-i))){
//                     max_len = j-i;
//                     max_str = s.substr(i, j-i);
//                 }
//             }
//         }
//         return max_str;
//     }
// };
// class Solution {
// public:
//     int dp[1001][1001];
//     bool solve(string &s, int l, int r){
//         if(l >= r){
//             return true;
//         }
//         if(dp[l][r] != -1) return dp[l][r];
//         if(s[l] == s[r]){
//             return dp[l][r] = solve(s, l+1, r-1);
//         }
//         return dp[l][r] = false;
//     }
//     string longestPalindrome(string s) {
//         int n = s.length();
//         int max_len = INT_MIN;
//         int startingIndex = 0;
//         memset(dp, -1, sizeof(dp));
//         for(int i=0; i<n; i++){
//             for(int j=i; j<n; j++){
//                 if(solve(s, i, j) && max_len < j-i+1){
//                     startingIndex = i;
//                     max_len = j-i+1;
//                 }
//             }
//         }
//         return s.substr(startingIndex, max_len);
//     }
// };
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n = s.length();
//         if(n <= 1) return s;

//         int maxlen = 1;
//         int startIndex = 0;
//         int end = 0;
//         vector<vector<bool>> dp(n, vector<bool>(n, false));

//         for(int i=0; i<n; i++){
//             dp[i][i] = true;
//             for(int j=0; j<i; j++){
//                 if(s[i] == s[j] && (j - i <= 2 || dp[j+1][i-1])){
//                     dp[j][i] = true;
//                     if(i - j + 1 > maxlen){
//                         maxlen = i - j + 1;
//                         startIndex = j;
//                         end = i;
//                     }
//                 }
//             }
//         }
//         return s.substr(startIndex, end - startIndex + 1);
//     }
// };
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n <= 1){
            return s;
        }
        auto expand_from_center = [&](int l, int r){
            while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
            }
            return s.substr(l+1, r-l-1);
        };
        string max_str = s.substr(0, 1);
        for(int i=0; i<n-1; i++){
            string odd = expand_from_center(i, i);
            string even = expand_from_center(i, i+1);
            if(max_str.length() < odd.length()){
                max_str = odd;
            }
            if(max_str.length() < even.length()){
                max_str = even;
            }
        }
        return max_str;
    }
};