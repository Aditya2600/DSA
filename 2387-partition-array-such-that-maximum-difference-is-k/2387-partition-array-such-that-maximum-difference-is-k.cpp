class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int ans = 0;
        while(i<n){
            int target = nums[i] + k;
            int pos = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
            i = pos;
            ans++;
        }
        return ans;
    }
};