// class Solution {
// public:
//     string frequencySort(string s) {
//         unordered_map<char, int> mp;
//         int n = s.size();
//         for (int i = 0; i < n; i++) {
//             mp[s[i]]++;
//         }
//         priority_queue<pair<int, char>> pq;
//         for (auto kv : mp) {
//             pq.push({kv.second, kv.first});
//         }
//         string ans;
//         while (!pq.empty()) {
//             auto [f, ch] = pq.top();
//             pq.pop();
//             ans.append(f, ch);
//         }
//         return ans;
//     }
// };


class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        for(auto ch : s){
            freq[ch]++;
        }
        vector<vector<char>> bucket(n+1);
        for(auto [ch, fq] : freq){
            bucket[fq].push_back(ch);
        }
        string ans = "";
        for(int i = n; i>=1; i--){
            for(auto ch : bucket[i]){
                ans.append(i, ch);
            }
        }
        return ans;
    }
};