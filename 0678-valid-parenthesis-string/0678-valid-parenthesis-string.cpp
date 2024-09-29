class Solution {
public:
    bool validParenthesis(string &s, int ind, int cnt) {
        int n = s.size();
        if (cnt < 0) {
            return false;
        }
        if (ind == n) {
            return cnt == 0;
        }
        if (s[ind] == '(') {
            return validParenthesis(s, ind + 1, cnt + 1);
        }
        else if (s[ind] == ')') {
            return validParenthesis(s, ind + 1, cnt - 1);
        } else {
        return (validParenthesis(s, ind + 1, cnt + 1) ||
                validParenthesis(s, ind + 1, cnt - 1) ||
                validParenthesis(s, ind + 1, cnt));
        }
    }
    bool checkValidString(string s) {
        int min = 0;
        int n = s.size();
        int max = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                min++;
                max++;
            }
            else if(s[i] == ')'){
                min--;
                max--;
            }
            else{
                min--;
                max++;
            }
            if(min < 0) min = 0;
            if(max < 0) return false;
        }
        return min == 0;
    }
};