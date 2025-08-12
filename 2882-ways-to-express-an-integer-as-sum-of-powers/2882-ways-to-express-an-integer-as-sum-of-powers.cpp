class Solution {
int dp[302][302];
#define MOD 1000000007
vector<int> powers;

    int binaryExponentiation(int a, int b){
        int res = 1;
        while(b){
            if(b & 1){
                res *= a;
            }
            a *= a;
            b >>= 1;
        }
        return res;
    }
//     int findWays(int pos, int target){
//         if(target == 0) return 1;
//         if(pos == powers.size() || target < 0) return 0;
//         if(dp[pos][target] != -1) return dp[pos][target];
//         int include = findWays(pos + 1, target - powers[pos]);
//         int exclude = findWays(pos + 1, target);
//         return dp[pos][target] = (include + exclude) % MOD;
//     }
// public:
//     int numberOfWays(int n, int x) {
//         for(int i=1; i<=n; i++){
//             int power = binaryExponentiation(i, x);
//             if(power > n) break;
//             powers.push_back(power);
//         }
//         memset(dp, -1, sizeof(dp));
//         return findWays(0, n);
//     }
public:
    // int numberOfWays(int n, int x) {
    //     vector<int> powers;
    //     for(int i=1; i<=n; i++){
    //         int power = binaryExponentiation(i, x);
    //         if(power > n) break;
    //         powers.push_back(power);
    //     }
    //     int p = powers.size();
    //     vector<vector<int>> dp(p+1, vector<int>(n+1, 0));
    //     for(int pos=1; pos<=p; pos++){
    //         dp[pos-1][0] = 1;
    //         for(int target = 1; target<=n; target++){
    //             if(powers[pos-1]>target){
    //                 dp[pos][target] = dp[pos-1][target];
    //             }
    //             else{
    //                 dp[pos][target] = (dp[pos-1][target] + dp[pos-1][target-powers[pos-1]]) % MOD;
    //             }
    //         }
            
    //     }
    //     return dp[p][n];
     int numberOfWays(int n, int x) {
        vector<int> powers;
        for(int i=1; i<=n; i++){
            int power = binaryExponentiation(i, x);
            if(power > n) break;
            powers.push_back(power);
        }
        vector<int> dp(n+1);
        dp[0] = 1;
        int p = powers.size();
        for(int pos=1; pos<=p; pos++){
            for(int target=n; target>=powers[pos-1]; --target){
                dp[target] = (dp[target] + dp[target-powers[pos-1]])%MOD;
            }
        }
        return dp[n];
    }
};