class Solution {
public:

    int f(int ind, vector<int>& coins, int amount, vector<vector<int>> &dp){
        if(amount == 0){
            return 0;
        }
        if(ind == -1){
            return 1e9;
        }

        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }    
        int take = 1e9;
        if(coins[ind] <= amount) take = 1 + f(ind, coins, amount - coins[ind], dp);
        int notTake = f(ind-1, coins, amount, dp);
        return dp[ind][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = f(n-1, coins, amount, dp);
        return (ans == 1e9) ? -1 : ans;
    }
};