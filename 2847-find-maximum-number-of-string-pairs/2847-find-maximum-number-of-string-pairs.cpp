class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;
        unordered_set<string> s;
        for(auto it : words){
            s.insert(it);
        }
        for(int i=0; i<n; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            if(words[i] == rev) continue;
            if(s.find(rev) != s.end()){
                count++;
                s.erase(words[i]);
            }
        }
        return count;
    }
};