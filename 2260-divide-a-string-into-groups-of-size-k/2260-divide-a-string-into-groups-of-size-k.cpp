class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.size();

        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k);  // may be shorter than k
            if (group.size() < k) {
                group += string(k - group.size(), fill);
            }
            ans.push_back(group);
        }

        return ans;
    }
};