class Solution {
    long long mod = 1e9 + 7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> ans;
        for(int i=0; (1<<i) <= n; i++){
            if(n & (1 << i)){
                powers.push_back(1<<i);
            }
        }
        int m = queries.size();
        for(int i = 0; i<m; i++){
            long long prod = 1;
            for(int k = queries[i][0]; k <= queries[i][1]; k++){
                prod = (prod * powers[k]) % mod;
            }
            ans.push_back(prod);
        }
        return ans;
    }
};