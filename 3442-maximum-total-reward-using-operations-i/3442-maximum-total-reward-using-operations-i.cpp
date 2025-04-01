class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(int i, int rewSum, vector<int>& rewardValues){
        if(rewSum > rewardValues.back()) return rewSum;
        if(i == n) return rewSum;

        if(dp[i][rewSum] != -1) return dp[i][rewSum];
        int take = (rewardValues[i] > rewSum) ? solve(i+1, rewSum + rewardValues[i], rewardValues) : rewSum;
        int notTake = solve(i+1, rewSum, rewardValues);
        return dp[i][rewSum] = max(take, notTake);
    }

    int maxTotalReward(vector<int>& rewardValues) {
        n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        dp = vector<vector<int>> (n+1, vector<int> (rewardValues.back() + 1, -1));

        return solve(0, 0, rewardValues);
    }
};