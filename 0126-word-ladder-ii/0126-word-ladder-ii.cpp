// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> st(wordList.begin(), wordList.end());
//         if(st.count(endWord) == 0) return {};
//         queue<vector<string>> q;
//         q.push({beginWord});
//         vector<string> usedOnLevel;
//         usedOnLevel.push_back(beginWord);
//         int level = 1;
//         vector<vector<string>> ans;
//         while(!q.empty()){
//             vector<string> vec = q.front();
//             q.pop();
//             if(vec.size() > level){
//                 level++;
//                 for(auto it : usedOnLevel){
//                     st.erase(it);
//                 }
//                 usedOnLevel.clear();
//             }
//             string word = vec.back();
//             if(word == endWord){
//                 if(ans.size() == 0){
//                     ans.push_back(vec);
//                 }
//                 else if(ans[0].size() == vec.size()){
//                     ans.push_back(vec);
//                 }
//             }
//             for(int i=0; i<word.size(); i++){
//                 char original = word[i];
//                 for(char ch = 'a'; ch <= 'z'; ch++){
//                     if(ch == original) continue;
//                     word[i] = ch;
//                     if(st.count(word) > 0){
//                         vec.push_back(word);
//                         q.push(vec);
//                         usedOnLevel.push_back(word);
//                         vec.pop_back();
//                     }
//                 }
//                 word[i] = original; 
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    private:
        void dfs(string word, vector<string> seq, string beginWord, vector<vector<string>>& ans, unordered_map<string, int>& mpp){
            if(word == beginWord){
                reverse(seq.begin(), seq.end());
                ans.push_back(seq);
                return;
            }
            int steps = mpp[word];
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                        seq.push_back(word);
                        dfs(word, seq, beginWord, ans, mpp);
                        seq.pop_back();
                    }
                }
                word[i] = original;
            }
        }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> mpp;
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        mpp.insert({beginWord, 0});
        
        while(!q.empty()){
            string word = q.front();
            q.pop();
            if(word == endWord) break;
            int level = mpp[word];
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.count(word) > 0){
                        q.push(word);
                        st.erase(word);
                        mpp.insert({word, level+1});
                    }
                }
                word[i] = original;
            }
        }
        vector<vector<string>> ans;
        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq, beginWord, ans, mpp);
        }
        return ans;
    }
};