class TrieNode{
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('\0');
    }
    void insert(string word) {
        TrieNode* curr = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            int index = ch - 'a';
            if(curr->children[index] == NULL){
                curr->children[index] = new TrieNode(ch);
                curr->childCount++;
            }
            curr = curr->children[index];
        }
        curr->isTerminal = true;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* t = new Trie();
        for (string str : strs) {
            t->insert(str);
        }
        string first = strs[0];
        string ans = "";

        TrieNode* curr = t->root;
        for(int i=0; i<first.length(); i++){
            char ch = first[i];
            int index = ch - 'a';
            if(curr->childCount == 1 && !curr->isTerminal){
                ans.push_back(ch);
                curr = curr->children[index];
            }
            else break;
        }
        return ans;
    }
};