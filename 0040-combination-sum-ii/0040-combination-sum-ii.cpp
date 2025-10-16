class Solution {
public:
    void solve(int idx, vector<int>& sets, vector<int>& candidates,
               int remaining, vector<vector<int>>& ans) {
        int n = candidates.size();
        if (remaining == 0) {
            ans.push_back(sets);
            return;
        }
        for (int i = idx; i < n; i++) {
            if (candidates[idx] > remaining)
                break;
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;
            sets.push_back(candidates[i]);
            solve(i + 1, sets, candidates, remaining - candidates[i], ans);
            sets.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> sets;
        vector<vector<int>> ans;
        solve(0, sets, candidates, target, ans);
        return ans;
    }
};