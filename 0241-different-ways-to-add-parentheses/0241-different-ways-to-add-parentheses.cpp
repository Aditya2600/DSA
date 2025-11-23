class Solution {
public:
    vector<int> solve(string s) {
        vector<int> res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
                vector<int> left_results = solve(s.substr(0, i));
                vector<int> right_results = solve(s.substr(i + 1));

                for (auto& x : left_results) {
                    for (auto& y : right_results) {
                        if (s[i] == '+') {
                            res.push_back(x + y);
                        } else if (s[i] == '*') {
                            res.push_back(x * y);
                        } else {
                            res.push_back(x - y);
                        }
                    }
                }
            }
        }
        if(res.empty()){
            res.push_back(stoi(s));
        }
        return res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};