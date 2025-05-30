class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int ans1 = 0;
        int ans2 = 0;
        sort(nums.begin(), nums.end());
            ans1 = nums[0] * nums[1] * nums[n-1];
            ans2 = nums[n-1] * nums[n-2] * nums[n-3];
            return max(ans1, ans2);
    }
};