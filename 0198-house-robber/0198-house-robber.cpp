class Solution {
public:
    // vector<int> dp;
    // int f(int ind, vector<int>& nums){
    //     int n = nums.size();
    //     if(dp[ind] != -1) return dp[ind];
    //     if(ind == n-1) return nums[ind];
    //     if(ind == n-2) return max(nums[ind], nums[ind+1]);
    //     int take = nums[ind] + f(ind+2, nums);
    //     int notTake = f(ind+1, nums);
    //     return dp[ind] = max(take, notTake);
    // }
    int rob(vector<int>& nums) {
        // dp.resize(nums.size()+1, -1);
        // return f(0, nums);
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2], nums[n-1]);
        for(int ind = n-3; ind >= 0; ind--){
            int take = nums[ind] + dp[ind+2];
            int notTake = dp[ind+1];
            dp[ind] = max(take, notTake);
        }
        return dp[0];
    }
};