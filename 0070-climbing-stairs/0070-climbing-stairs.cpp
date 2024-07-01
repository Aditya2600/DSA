class Solution {
public:

    int solve(int curr, int n, vector<int> &dp){
        if(curr == n) return 1;
        if(curr > n) return 0;
        if(dp[curr]!=-1) return dp[curr];
        int curr_ways = solve(curr+1,n,dp);
        curr_ways+=solve(curr+2,n,dp);
        dp[curr] = curr_ways;
        return dp[curr];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(0,n,dp);
    }
};