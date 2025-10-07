class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int m = 1 << n;
        vector<vector<int>> powerSet;

        for (int i = 0; i < m; i++) {
            vector<int> set;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    set.push_back(nums[j]);
                }
            }
            powerSet.push_back(set);
        }
        return powerSet;
    }
};