class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto kv : mp) {
            pq.push({kv.second, kv.first});
        }
        string ans;
        while (!pq.empty()) {
            auto [f, ch] = pq.top();
            pq.pop();
            ans.append(f, ch);
        }
        return ans;
    }
};