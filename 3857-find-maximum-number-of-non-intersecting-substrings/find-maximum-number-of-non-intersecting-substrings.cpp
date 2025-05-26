class Solution {
public:
    int maxSubstrings(string word) {
        int n = word.size();
        if (n < 4) {
            return 0;
        }
        map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[word[i] - 'a'].push_back(i);
        }
        vector<pair<int, int>> intervals;
        for (auto a : pos) {
            for (int k = 0; k < a.second.size(); k++) {
                int need = a.second[k] + 3;
                auto it = lower_bound(a.second.begin(), a.second.end(), need);
                if (it != a.second.end()) {
                    intervals.push_back({a.second[k], *it});
                }
            }
        }

        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a.second < b.second; });
        int ans = 0, last_ind = -1;
        for (auto it : intervals) {
            if (it.first > last_ind) {
                ans++;
                last_ind = it.second;
            }
        }

        return ans;
    }
};