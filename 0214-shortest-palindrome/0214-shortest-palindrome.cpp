class Solution {
public:
    vector<int> kmp(string s){
        vector<int> lps(s.size(),0);
        for(int i=1; i<s.size(); i++){
            int prev_idx = lps[i-1];
            while(prev_idx > 0 && s[i]!=s[prev_idx]){
                prev_idx = lps[prev_idx - 1];
            }
            lps[i] = prev_idx + (s[i] == s[prev_idx] ? 1:0);
        }
        return lps;
    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        string a = s+'$'+t;
        vector<int> p = kmp(a);
        int matched = p[a.size()-1];
        string appendChars = s.substr(matched);
        reverse(appendChars.begin(), appendChars.end());
        return appendChars + s;
    }
};