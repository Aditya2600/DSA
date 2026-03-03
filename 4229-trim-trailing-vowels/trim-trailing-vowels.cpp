class Solution {
public:
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }

    string trimTrailingVowels(string s) {
        int n = (int)s.size();
        int l = 0, r = n - 1;   // l isn't strictly needed, but keeps it "two-pointer style"

        while (r >= l && isVowel(s[r])) {
            r--;
        }

        // keep [0..r]
        return s.substr(0, r + 1);
    }
};