class Solution {
public:
    vector<string> ans;
    vector<string> keys = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void fun(string &digits,string &temp, int ind){
            int n = digits.size();
            if(ind == n){
                ans.push_back(temp);
                return;
            }
            int curr_ind = digits[ind] - '0';
            for(auto &key:keys[curr_ind]){
                temp.push_back(key);
                fun(digits,temp,ind+1);
                temp.pop_back();
            }

    }
    vector<string> letterCombinations(string digits) {
       if(digits.size() == 0){
        return ans;
       }
       string temp;
       fun(digits,temp,0);
       return ans; 
    }
};