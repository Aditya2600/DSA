class Solution {
public:
    string clearStars(string s) {
        int n = s.size();
        vector<vector<int>> mp(26);
        for(int i=0; s[i]; i++){
            if(s[i] == '*'){
                for(int j=0; j<26; j++){
                    if(mp[j].size() > 0){
                        s[mp[j].back()] = '*';
                        mp[j].pop_back();
                        break;
                    }
                }
            }
            else{
                mp[s[i] - 'a'].push_back(i);
            }
        }
        string res;
        for(char c : s){
            if(c != '*'){
                res.push_back(c);
            }
        }
        return res;
    }
};