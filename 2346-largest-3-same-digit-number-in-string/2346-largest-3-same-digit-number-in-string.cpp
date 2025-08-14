class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int n = num.size();
        for (int i = 0; i + 2 < n; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                string cur = num.substr(i, 3);
                if (cur > ans) ans = cur; // lexicographic comparison works for same length
            }
        }
        return ans;
    }
};