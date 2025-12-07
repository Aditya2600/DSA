class Solution {
public:
    bool check(int n){
        string s = "";
        while(n > 0){
            s += (n & 1);
            n = (n >> 1);
        }
        int i = 0;
        int j = s.size() - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        vector<int> pl;
        for(int i=1; i<=5000; i++){
            if(check(i)){
                pl.push_back(i);
            }
        }
        vector<int> ans;
        for(int i : nums){
            int mini = 1e9;
            for(int j : pl){
                mini = min(mini, abs(j - i));
            }
            ans.push_back(mini);
        }
        return ans;
    }
};