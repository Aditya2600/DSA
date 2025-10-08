// class Solution {
// public:
//     void solve(int ind, vector<int>& nums, vector<vector<int>>& ans,
//                vector<int>& ds) {
//         int n = nums.size();
//         ans.push_back(ds);
//         for (int i = ind; i < n; i++) {
//             if (i != ind && nums[i] == nums[i - 1]) {
//                 continue;
//             }
//             ds.push_back(nums[i]);
//             solve(i + 1, nums, ans, ds);
//             ds.pop_back();
//         }
//     }

//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {

//         vector<vector<int>> ans;
//         vector<int> ds;
//         sort(nums.begin(), nums.end());
//         solve(0, nums, ans, ds);
//         return ans;
//     }
// };
class Solution {
public:
    void solve(int i, vector<int> nums, set<vector<int>>&st, vector<int> temp){
        if(i==nums.size()){
            st.insert(temp);
            return;
        }
        solve(i+1,nums,st,temp);
        temp.push_back(nums[i]);
        solve(i+1,nums,st,temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, nums, st, ds);
        vector<vector<int>> ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};