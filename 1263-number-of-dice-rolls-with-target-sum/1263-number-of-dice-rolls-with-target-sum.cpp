#define ll long long int
class Solution {
public:
    /*int helper(int n, int k, int target, int mod, vector<vector<int>> &dp){
        if(target == 0 && n == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][target] != -1) return dp[n][target];
        int sum = 0;
        for(int i=1; i<=k; i++){
            if(target - i < 0) continue;
            sum = ((sum % mod) + helper(n-1, k, target - i, mod, dp))%mod;
        }
        return dp[n][target] = sum % mod;
    }*/
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(35,vector<int> (1005,0));
        dp[0][0] = 1;
        for(int dice=1; dice<=n; dice++){
            for(int j=1; j<=target; j++){
            
            for(int face=1; face<=k; face++){
                if(j - face >= 0){
                dp[dice][j] = (dp[dice][j] % mod + dp[dice-1][j - face]%mod) % mod;
            }
            }
        }
        }
        return dp[n][target];
    }
};