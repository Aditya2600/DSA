class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long base = 0;
        for(int i=0; i<n; i++){
            base += (prices[i] * strategy[i]);
        }
        long long slide = 0;
        long long ans = base;
        for(int i=0; i<k; i++) base -= (prices[i] * strategy[i]);
        for(int i=k/2; i<k; i++) slide += (prices[i]);
        ans = max(ans, base + slide);

        for(int i=k; i<n; i++){
            base -= (prices[i] * strategy[i]);
            base += (prices[i-k] * strategy[i-k]);
            slide += (prices[i]);
            slide -= (prices[i-k/2]);
            ans = max(ans, base + slide);
        } 
        return ans;
    }
};