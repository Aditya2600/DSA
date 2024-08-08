class Solution {
public:
    int f(vector<int>& nums, int target, int i){
        if(i < 0){
            // If the target is 0, we've found a valid way to reach the target
            return target == 0 ? 1 : 0;
        }
        int take =  f(nums, target - nums[i], i-1);
        int notTake = f(nums, target + nums[i], i-1);
        return take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size()-1;
        return f(nums, target, n);
    }
};