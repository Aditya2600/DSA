class Solution {
public:
    // vector<int> dp;
    // int solve(int n){
    //     if(n <= 0) return 0;
    //     if(dp[n] != -1) return dp[n];
    //             int ans = n;
    //             for(int i=1; i*i <= n; i++){
    //                 int square = i * i;
    //                 ans = min(ans, 1 + solve(n - square));
    //             }
    //             return dp[n] = ans;
    // }

    // int numSquares(int n) {
    //     dp.resize(n+1, - 1);
    //     return solve(n);
    // }

    int numSquares(int n){
        int sqrtVal = (int) sqrt(n);
        if(sqrtVal * sqrtVal == n) return 1;

        while(n % 4 == 0){
            n /= 4;
        }
        if(n % 8 == 7){
            return 4;
        }
        for(int i=1; i*i <= n; i++){
            int squareA = i*i;
            int elementB = (int) sqrt(n - squareA);
            if(elementB * elementB == n - squareA){
                return 2;
            }
        }
        return 3;

        // vector<int> dp = vector<int> (n+1, 0);
        // for(int i=1; i<=n; i++){
        //     dp[i] = i;
        //     for(int j=1; j*j<=i; j++){
        //         int square = j*j;
        //         dp[i] = min(dp[i], 1 + dp[i - square]);
        //     }
        // }
        // return dp[n];
    }
};