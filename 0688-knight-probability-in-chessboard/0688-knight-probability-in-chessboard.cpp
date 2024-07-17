class Solution {
public:
    double dp[30][30][105];
    double f(int n, int k, int i, int j){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(k == 0) return 1;
        double ans = 0.0;
        if(dp[i][j][k] > -0.9) return dp[i][j][k];
        ans += f(n, k-1, i+2,j+1) * (0.125);
        ans += f(n, k-1, i-2,j+1) * (0.125);
        ans += f(n, k-1, i+2,j-1) * (0.125);
        ans += f(n, k-1, i-2,j-1) * (0.125);
        ans += f(n, k-1, i+1,j+2) * (0.125);
        ans += f(n, k-1, i-1,j+2) * (0.125);
        ans += f(n, k-1, i+1,j-2) * (0.125);
        ans += f(n, k-1, i-1,j-2) * (0.125);
        return dp[i][j][k] = ans;
    }
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, -1, sizeof dp);
        return f(n, k, row, column);
    }
};