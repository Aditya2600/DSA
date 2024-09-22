class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())return false;
        unordered_map<char, int> mp1,mp2;
        for(auto ch : s){
            mp1[ch]++;
        }
        for(auto it : t){
            mp2[it]++;
        }
        for(auto x : mp1){
            if(mp2.find(x.first) == mp2.end()) return false;
            if(mp2[x.first] != x.second) return false;
        }
        return true;
    }
};