class Solution {
public:
    bool isPalindromeRange(const string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                // Try skipping left or right character
                return isPalindromeRange(s, l+1, r) || isPalindromeRange(s, l, r-1);
            }
            l++;
            r--;
        }
        return true;
    }
};