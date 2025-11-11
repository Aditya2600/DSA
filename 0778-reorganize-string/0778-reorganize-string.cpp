class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        for (char ch : s) {
            freq[ch - 'a']++;

            if (freq[ch - 'a'] > ((n + 1) / 2)) {
                return "";
            }
        }
        string res = "";
        priority_queue<pair<int, char>> pq;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (freq[ch - 'a'] > 0) {
                pq.push({freq[ch - 'a'], ch});
            }
        }
        while (pq.size() >= 2) {
            auto p1 = pq.top();
            pq.pop();
            auto p2 = pq.top();
            pq.pop();
            res.push_back(p1.second);
            res.push_back(p2.second);

            p1.first--;
            p2.first--;
            if (p1.first > 0) {
                pq.push(p1);
            }
            if (p2.first > 0) {
                pq.push(p2);
            }
        }
        if(!pq.empty()){
            res.push_back(pq.top().second);
        }
        return res;
    }
};