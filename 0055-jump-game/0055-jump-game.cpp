class Solution {
public:
    bool jumpGame(vector<int>& nums, int ind) {
        int n = nums.size();
        if (ind >= n - 1)
            return true;
        int maxJump = nums[ind];
        for (int i = 1; i <= maxJump; i++) {
            return jumpGame(nums, ind + maxJump);
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxind = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxind)
                return false;
            maxind = max(maxind, i + nums[i]);
        }
        return true;
    }
};