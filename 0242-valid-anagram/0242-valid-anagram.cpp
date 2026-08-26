class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        for(int j=0; j<t.size(); j++){
            mp[t[j]]--;
        }
        for(auto x : mp){
            if(x.second != 0){
                return false;
            }
        }
        return true;
    }
};