class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false; // odd sum can't be split equally

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // sum 0 is always possible

        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};