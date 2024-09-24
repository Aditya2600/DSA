class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        vector<int> lastSeen(3, -1);
        for(int i=0; i < n; i++){
            lastSeen[s[i] - 'a'] = i;
            cnt = cnt + (1 + min({lastSeen[0], lastSeen[1], lastSeen[2]}));
        }
        return cnt;
    }
};