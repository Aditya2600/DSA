class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++) {

            if (abs(nums[i] - (nums[i + 1])) > maxi) {
                maxi = abs(nums[i] - nums[i + 1]);
            }
            int circularDiff = abs(nums[nums.size() - 1] - nums[0]);
            maxi = max(maxi, circularDiff);
        }
        return maxi;
    }
};