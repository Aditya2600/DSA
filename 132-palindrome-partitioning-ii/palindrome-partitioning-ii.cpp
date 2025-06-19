class Solution {
public:
    bool isPalindrome(string& s, int i, int j){
        while(i <= j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    }
    int f(int i, string &s, vector<int>& dp, int n){
        if(i == s.size()){
            return 0;
        }
        int minCost = INT_MAX;
        if(dp[i] != -1) return dp[i];
        for(int j=i; j<s.size(); j++){
            if(isPalindrome(s, i, j)){
                int cost = 1 + f(j+1, s, dp, n);
                minCost = min(minCost, cost);
            }
        }
        
        return dp[i] = minCost;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp, n) - 1;
    }
};