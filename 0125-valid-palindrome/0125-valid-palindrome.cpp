class Solution {
public:
    string f(string s) {
        int n = s.size();
        string palin = "";
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                palin.push_back(tolower(s[i]));
            } else if (s[i] >= 'a' && s[i] <= 'z') {
                palin.push_back(s[i]);
            } else
                continue;
        }
        return palin;
    }
    bool isPalindrome(string s) {
        string palin = f(s);
        int n = palin.size();
        int l = 0;
        int r = n-1;
        while(l < r){
            if(palin[l] != palin[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};