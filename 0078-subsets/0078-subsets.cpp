// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         int m = 1 << n;
//         vector<vector<int>> powerSet;

//         for (int i = 0; i < m; i++) {
//             vector<int> set;
//             for (int j = 0; j < n; j++) {
//                 if (i & (1 << j)) {
//                     set.push_back(nums[j]);
//                 }
//             }
//             powerSet.push_back(set);
//         }
//         return powerSet;
//     }
// };
class Solution {
public:

    void solve(vector<int>& nums, int ind, vector<vector<int>> &ans, vector<int> &set){
        int n = nums.size();
        if(ind >= n){
            ans.push_back(set);
            return;
        }
        set.push_back(nums[ind]);
        solve(nums, ind+1, ans, set);
        set.pop_back();
        solve(nums, ind+1, ans, set);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> set;
        solve(nums, 0, ans, set);
        return ans;
    }
};