class Solution {
public:

    vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;

    void solve(int idx, string& digits, string& temp){
        if(idx == digits.size()){
            ans.push_back(temp);
            return;
        }
        int index = digits[idx] - '0';
         
        for(auto &ch : keys[index]){
            temp.push_back(ch);
            solve(idx+1, digits, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return {};
        }
        string temp = "";
        solve(0, digits, temp);
        return ans;
    }
};