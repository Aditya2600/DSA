class Solution {
public:
    void solve(int idx, vector<int>& set, vector<int>& candidates,
               int remaining, vector<vector<int>>& ans) {
        int n = candidates.size();
        if (remaining == 0) {
            ans.push_back(set);
            return;
        }
        if (idx == n) {
            return;
        }
        for (int i = idx; i < n; i++) {
            if (candidates[i] > remaining)
                break;

            set.push_back(candidates[i]);

            solve(i, set, candidates, remaining - candidates[i], ans);

            set.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> set;
        vector<vector<int>> ans;
        solve(0, set, candidates, target, ans);
        return ans;
    }
};