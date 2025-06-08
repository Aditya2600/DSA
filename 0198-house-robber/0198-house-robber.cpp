class Solution {
public:
    vector<int> dp;
    int f(int ind, vector<int>& nums){
        int n = nums.size();
        if(dp[ind] != -1) return dp[ind];
        if(ind == n-1) return nums[ind];
        if(ind == n-2) return max(nums[ind], nums[ind+1]);
        int take = nums[ind] + f(ind+2, nums);
        int notTake = f(ind+1, nums);
        return dp[ind] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        dp.resize(nums.size()+1, -1);
        return f(0, nums);
    }
};