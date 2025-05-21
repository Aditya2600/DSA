class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        vector<int> ans;
        for(auto num : nums){
            if(!vis[num]){
                vis[num] = true;
            }
            else ans.push_back(num);        
        }
        return ans;
    }
};