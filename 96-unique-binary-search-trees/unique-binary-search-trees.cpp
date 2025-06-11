class Solution {
public:
    int dp[20];
    int f(int n){
        if(n == 0 || n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];
        int sum = 0;
        for(int k=1; k<=n; k++){
            sum = sum + f(k-1)*f(n-k);
        }
        return dp[n] =  sum;
    }
    int numTrees(int n) {
        memset(dp, -1, sizeof dp);
        return f(n);
    }
};