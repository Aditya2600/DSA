class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(int i=0; i<n; i++){
            freq[s[i] - 'a']++;
        }
        vector<int> odd,even;
        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;
            if(freq[i] % 2 == 1 ){
                odd.push_back(freq[i]);
            }
            else even.push_back(freq[i]);
        }
        // for(int i=0; i<26; i++){
        //     if(freq[i] != 0 && freq[i] % 2 == 1 ){
        //         odd = max(freq[i], odd);
        //     }
        //     else if(freq[i] != 0 &&  freq[i] % 2 == 0){
        //         even = min(even, freq[i]);
        //     }
        //     else return 0;
        // }
        int ans = *max_element(odd.begin(),odd.end())  - *min_element(even.begin(),even.end());
        return ans;
    }
};