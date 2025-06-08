class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int, int> mp;
        int n = x.size();
        for(int i=0; i<n; i++){
            mp[x[i]] = max(mp[x[i]], y[i]);
        }
        vector<int> v;
        for(auto e : mp){
            v.push_back(e.second);
        }
        int m = v.size();
        sort(v.begin(), v.end());
        if(m < 3){
            return -1;
        }
        else return v[m-1] + v[m-2] + v[m-3];
    }
};