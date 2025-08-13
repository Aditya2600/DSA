class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
            if(find(ans.begin(), ans.end(), nums[i]) == ans.end() && mp[nums[i]] > n/3){
                ans.push_back(nums[i]);
            }
        }
    return ans;
    }
};