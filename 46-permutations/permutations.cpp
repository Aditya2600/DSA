class Solution {
public:
    void backTrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, vector<bool> used){
        int n = nums.size();
        if(res.size() == n){
            ans.push_back(res);
            return;
        }
        for(int i=0; i<n; i++){
            if(used[i]) continue;
            used[i] = true;
            res.push_back(nums[i]);
            backTrack(nums, ans, res, used);
            res.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> used(nums.size(), false);
        backTrack(nums, ans, res, used);
        return ans;
    }
};