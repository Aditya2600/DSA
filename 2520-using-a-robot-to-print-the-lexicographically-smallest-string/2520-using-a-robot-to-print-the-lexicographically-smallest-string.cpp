class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string result = "";
        string t = "";

        for (char c : s) {
            t.push_back(c);
            freq[c - 'a']--;

            // Find the smallest character remaining in s
            while (!t.empty()) {
                char minChar = 0;
                while (minChar < 26 && freq[minChar] == 0) minChar++;

                if (!t.empty() && (minChar == 26 || t.back() <= 'a' + minChar)) {
                    result += t.back();
                    t.pop_back();
                } else {
                    break;
                }
            }
        }

        return result;
    }
};