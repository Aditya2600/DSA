class Solution {
public:

    long long f(string &word, int k){
        int i = 0;
        int j = 0;
        long long ans = 0;

        map<char,int> mp;
        int cnt = 0;

        while(j < word.size()){
            if(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u'){
                mp[word[j]]++;
            }
            else{
                cnt++;
            }
            while(mp.size() == 5 && cnt >= k){
                ans += word.size() - j;
                if(mp.find(word[i]) != mp.end()){
                    mp[word[i]]--;
                    if(mp[word[i]] == 0){
                        mp.erase(word[i]);
                    }
                }
                else{
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k+1);
    }
};