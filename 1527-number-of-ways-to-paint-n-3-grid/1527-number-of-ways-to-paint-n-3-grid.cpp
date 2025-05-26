class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> patterns;
    vector<vector<int>> comp;
    
    void dfs(int row, int m, vector<int> cur){
        if(row == m){
            patterns.push_back(cur);
            return;
        }

        for(int i = 0; i < 3; i++){
            if(row > 0 && cur[row - 1] == i) continue;
            cur[row] = i;
            dfs(row + 1, m, cur);
        }
    }

    void buildComp(){
        int k = patterns.size();
        comp.resize(k);

        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                bool f = true;
                for(int r = 0; r < (int)patterns[i].size(); r++){
                    if(patterns[i][r] == patterns[j][r]){
                        f = false;
                        break;
                    }
                }
                if(f) comp[i].push_back(j); 
            }
        }
    }

    int solve(vector<vector<int>>& dp, int col, int prevCol, int n){
        if(col == n) return 1;
        if(dp[col][prevCol + 1] != -1) return dp[col][prevCol + 1];

        long long ways = 0;
        if(prevCol == -1){
            for(int i = 0; i < (int)patterns.size(); i++){
                ways = (ways + solve(dp, col + 1, i, n)) % MOD;
            }
        }
        else{
            for(auto colu : comp[prevCol]){
                ways = (ways + solve(dp, col + 1, colu, n)) % MOD;
            }
        }

        return dp[col][prevCol + 1] = ways;
    }
    int numOfWays(int n) {
        vector<int> cur(3);
        dfs(0, 3, cur);
        buildComp();
        vector<vector<int>> dp(n, vector<int>(patterns.size() + 1, -1));
        return solve(dp, 0, -1, n);
    }
}; 