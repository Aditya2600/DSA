class Solution {
public:
    int subarraysWithKDistinctHelper(vector<int>& nums, int k) {
        int l = 0, r = 0, cnt = 0;
        unordered_map<int, int> mp;
        while(r < nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKDistinctHelper(nums, k) - subarraysWithKDistinctHelper(nums, k-1);
    }
};