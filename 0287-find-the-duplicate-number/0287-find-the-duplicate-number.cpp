class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < n){
            if(nums[nums[i]] == nums[i]) return nums[i];
            else swap(nums[i], nums[nums[i]]);
        }
        return 0;
    }
};