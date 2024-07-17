class Solution {
public:
    int dp[30005][2];
    int f(vector<int> &prices, int i, bool on){
        int n = prices.size();
        int res = INT_MIN;
        if(dp[i][on] != -1) return dp[i][on];
        if(i == n) return 0;
        res = f(prices, i+1, on);
        if(on){
            res = max(res, prices[i] + f(prices, i+1, false));
        }
        else res = max(res , - prices[i] + f(prices, i+1, true));
        return dp[i][on] = res;
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        int n = prices.size();
        return f(prices, 0, false);
    }
};