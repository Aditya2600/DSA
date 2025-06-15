class Solution {
public:
    string generateTag(string caption) {
        bool caps = false;
        string ans = "#";
        for (char& x : caption) {
            if (x == ' ') {
                if (ans.size() > 1) {
                    caps = true;
                }
            } else {
                if (caps) {
                    ans.push_back(toupper(x));
                } else
                    ans.push_back(tolower(x));
                caps = false;
            }
            if(ans.size() == 100) break;
        }
        return ans;
    }
};