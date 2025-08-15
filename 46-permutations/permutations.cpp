class Solution {
public:

    void recurpermute(vector<int>& nums, vector<int>& ds, vector<bool>& flag, vector<vector<int>>& ans){
        int n = nums.size();
        if(ds.size() == n){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<n; i++){
            if(!flag[i]){
                flag[i] = true;
                ds.push_back(nums[i]);
                recurpermute(nums, ds, flag, ans);
                ds.pop_back();
                flag[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> flag(n, false);
        recurpermute(nums, ds, flag, ans);
        return ans;
    }
};