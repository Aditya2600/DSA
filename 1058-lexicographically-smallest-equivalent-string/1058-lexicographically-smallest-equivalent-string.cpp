class Solution {
public:
    vector<int> parent;
    void initDSU() {

        parent.resize(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }
    char findUPar(int x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }
    void UnionByRank(int c1, int c2) {
        int ulp_c1 = findUPar(c1);
        int ulp_c2 = findUPar(c2);
        if (ulp_c1 == ulp_c2)
            return;
        if (ulp_c2 < ulp_c1) {
            parent[ulp_c1] = ulp_c2;
        } else
            parent[ulp_c2] = ulp_c1;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        initDSU();
        vector<vector<int>> adj;
        int n = s1.size();    
        
        for (int i = 0; i < n; i++) {
            UnionByRank(s1[i] - 'a', s2[i] - 'a');
        }
        string ans = "";
        for (int i = 0; i < baseStr.size(); i++) {           
            int root = findUPar(baseStr[i] - 'a');
            ans += (char)(root + 'a');
        }
        return ans;
    }
};