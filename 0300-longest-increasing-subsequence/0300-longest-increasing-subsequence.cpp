class Solution {
public:
    // int f(vector<int>& nums, int ind, int prev_ind, vector<vector<int>>& dp) {
    //     int n = nums.size();
    //     if (ind == n)
    //         return 0;
    //     if (dp[ind][prev_ind + 1] != -1)
    //         return dp[ind][prev_ind + 1];
    //     int len = f(nums, ind + 1, prev_ind, dp);
    //     if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
    //         len = max((1 + f(nums, ind + 1, ind, dp)), len);
    //     }
    //     return dp[ind][prev_ind + 1] = len;
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--) {
                int len = dp[ind + 1][prev_ind + 1];
                if (prev_ind == -1 || nums[ind] > nums[prev_ind]) {
                    len = max(1 + dp[ind + 1][ind + 1], len);
                }
                dp[ind][prev_ind + 1] = len;
            }
        }
        return dp[0][0];
    }
};