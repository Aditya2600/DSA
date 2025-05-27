class Solution {
public:
    bool adj(char a, char b){
        return abs(a - b) == 1 || abs(a - b) == 25;
    }
    string lexicographicallySmallestString(string s) {
        int n = s.size();
        vector<vector<bool>> deletable(n, vector<bool>(n, false));
        for(int i=0; i<n-1; i++){
            if(adj(s[i], s[i+1])){
                deletable[i][i+1] = true;
            }
        }
        for(int len=3; len<=n; len++){
            for(int i=0; i+len-1<n; i++){
                int j = i+len-1;
                if(adj(s[i], s[j]) && deletable[i+1][j-1]){
                    deletable[i][j] = true;
                    continue;
                }
                for(int k=i+1; k<j-1; k++){
                    if(deletable[i][k] && deletable[k+1][j]){
                        deletable[i][j] = true;
                        break;
                    }
                }
            }
        }
        string dp[n+1];
        dp[n] = "";
        for(int i=n-1; i>=0; i--){
            dp[i] = s[i] + dp[i+1];
            for(int j=i+1; j<n; j++){
                if(deletable[i][j]){
                    dp[i] = min(dp[i], dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};