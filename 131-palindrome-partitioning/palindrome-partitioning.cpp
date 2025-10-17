class Solution {
public:
    bool isPalindrome(const string &s, int l, int r) {
        while (l < r) {
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void backTrack(int ind, string s, vector<string>& palindrome,
                   vector<vector<string>>& res) {
        int n = s.size();
        if (ind == n) {
            res.push_back(palindrome);
            return;
        }
        for (int i = ind; i < n; i++) {
            if (isPalindrome(s, ind, i)) {
                palindrome.push_back(s.substr(ind, i-ind+1));
                backTrack(i + 1, s, palindrome, res);
                palindrome.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> palindrome;
        backTrack(0, s, palindrome, res);
        return res;
    }
};