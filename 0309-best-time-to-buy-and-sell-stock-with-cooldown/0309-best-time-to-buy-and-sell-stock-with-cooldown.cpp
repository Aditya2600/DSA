class Solution {
public:
    // int f(int ind, int buy, vector<int>& prices, vector<vector<int>> dp) {
    //     if (ind >= prices.size())
    //         return 0;
    //     if (dp[ind][buy] != -1)
    //         return dp[ind][buy];
    //     if (buy == 1) {
    //         return dp[ind][buy] = max(f(ind + 1, 0, prices, dp) - prices[ind],
    //                                   f(ind + 1, 1, prices, dp));
    //     }
    //     return dp[ind][buy] = max(prices[ind] + f(ind + 2, 1, prices, dp),
    //                               f(ind + 2, 0, prices, dp));
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            dp[ind][1] = max(dp[ind + 1][0] - prices[ind], dp[ind + 1][1]);
            dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
        }
        return dp[0][1];
    }
};