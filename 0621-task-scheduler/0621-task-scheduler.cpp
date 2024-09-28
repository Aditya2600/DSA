class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(auto ch : tasks){
            freq[ch - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int maxfreq = freq[0];
        int maxcount = 0;
        for(auto f : freq){
            if(f == maxfreq) maxcount++;
            else break;
        }
        int result = (maxfreq - 1)*(n + 1) + maxcount;
        return max(result, (int)tasks.size());
    }
};