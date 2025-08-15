class Solution {
public:
    void recurpermute(int ind, vector<vector<int>>& ans, vector<int>& nums) {
        int n = nums.size();
        if (ind == n) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int i = ind; i < n; i++) {
            if (used.count(nums[i])) continue; // skip duplicate value at this depth
            used.insert(nums[i]);
            swap(nums[ind], nums[i]);
            recurpermute(ind + 1, ans, nums);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        recurpermute(0, ans, nums);
        return ans;
    }
};
