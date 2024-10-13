class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> qu;
        qu.push({beginWord, 1});
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!qu.empty()){
            string word = qu.front().first;
            int step = qu.front().second;
            qu.pop();
            if(word == endWord) return step;
            for(int i=0; i<word.length(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        qu.push({word, step + 1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
    }
};