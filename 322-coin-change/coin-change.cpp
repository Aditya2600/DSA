class Solution {
public:
    int f(vector<int>& coins, int amount, vector<int>& dp){
        if(amount == 0) return 0;
        int n = coins.size();
        if(dp[amount] != -2) return dp[amount];
        int result = INT_MAX;
        for(int i=0; i<n; i++){
            if(amount - coins[i] < 0) continue;
            result = min(result, f(coins, amount - coins[i], dp));
        }
        if(result == INT_MAX) return dp[amount] = INT_MAX;
        return dp[amount] = 1 + result;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(1000006, -2);
        int ans = f(coins, amount, dp);
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};