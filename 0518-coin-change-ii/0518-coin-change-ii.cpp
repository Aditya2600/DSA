class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,0));
        for(int t = 0; t <= amount; t++){
            dp[0][t] = (t % coins[0] == 0);
        }
        for(int ind = 1; ind < n; ind++){
            for(int t = 0; t<=amount; t++){
                int notTake = dp[ind - 1][t];
                int take = 0;
                if(coins[ind] <= t) take = dp[ind][t-coins[ind]];
                dp[ind][t] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};