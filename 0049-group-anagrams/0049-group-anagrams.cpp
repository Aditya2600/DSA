class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagram;
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        for(auto s:strs){
            string originalString = s;
            sort(s.begin(), s.end());
            mp[s].push_back(originalString);
        }
        for(auto [key, vectorOfStrings] : mp){
            anagram.push_back(vectorOfStrings);
        }
        return anagram;
    }
};