class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        queue<pair<string, int>> qu;
        qu.push({beginWord, 1});
        unordered_set<string> st;
        for (auto it : wordList) {
            st.insert(it);
        }
        while (!qu.empty()) {
            auto it = qu.front();
            qu.pop();
            string s = it.first;
            int steps = it.second;
            for (int i = 0; i < s.size(); i++) {
                char original = s[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    s[i] = ch;
                    if (st.find(s) != st.end()) {
                        if (s == endWord) {
                            return steps + 1;
                        }
                        qu.push({s, steps + 1});
                        st.erase(s);
                    }
                }
                s[i] = original;
            }
        }
        return 0;
    }
};