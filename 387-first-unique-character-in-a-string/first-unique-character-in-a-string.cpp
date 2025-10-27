// class Solution {
// public:
//     int firstUniqChar(string s) {
//         vector<int> freq(26, 0);
//         int n = s.size();
//         for(int i=0; i<n; i++){
//             freq[s[i] - 'a']++;
//         }
//         for(int i=0; i<n; i++){
//             if(freq[s[i] - 'a'] == 1) return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        int n = s.size();
        queue<int> q;

        for(int i=0; i<n; i++){
            int idx = s[i] - 'a';
            freq[idx]++;
            q.push(i);
            while(!q.empty() && freq[s[q.front()] - 'a'] > 1){
                q.pop();
            }
        }
        return q.empty() ? -1 : q.front();
    }
};