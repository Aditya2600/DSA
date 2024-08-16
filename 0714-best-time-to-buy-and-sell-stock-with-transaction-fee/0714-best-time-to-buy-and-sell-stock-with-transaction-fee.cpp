class Solution {
public:
    // int f(vector<int>& prices, int fee, int ind, int buy, vector<vector<int>> dp) {
    //     int n = prices.size();
    //     if (ind == n)
    //         return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     if (buy == 1) {
    //         return dp[ind][buy] = max(f(prices, fee, ind + 1, 0, dp) - prices[ind],
    //                    f(prices, fee, ind + 1, 1, dp));
    //     } else
    //         return dp[ind][buy] = max(f(prices, fee, ind + 1, 1, dp) + prices[ind] - fee,
    //                    f(prices, fee, ind + 1, 0, dp));
    // }
    int maxProfit(vector<int>& prices, int fee) { 
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        for(int ind = n-1; ind >= 0; ind--){
             
             dp[ind][1] = max(dp[ind + 1][0] - prices[ind],
                       dp[ind + 1][1]);
       
             dp[ind][0] = max(dp[ind + 1][1] + prices[ind] - fee,
                       dp[ind + 1][0]);
        }
        return dp[0][1]; 
        }
};