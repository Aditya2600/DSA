class Solution {
public:
    int minFallingPathSumHelper(vector<vector<int>>& matrix, int r, int col){
        int n = matrix.size();
        if(r >= n) return 0;
        if(col < 0 || col >= n) return 1e8;
        int leftd = matrix[r][col] + minFallingPathSumHelper(matrix, r+1, col-1);
        int below = matrix[r][col] + minFallingPathSumHelper(matrix, r+1, col);
        int rightd = matrix[r][col] + minFallingPathSumHelper(matrix, r+1, col+1);
        return min(leftd ,min(below, rightd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e8;
        vector<vector<int>> dp(n ,vector<int> (n,0));
        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int leftd = matrix[i][j];
                if(j-1>=0) leftd += dp[i-1][j-1];
                else leftd += 1e8;
                int below = matrix[i][j] + dp[i-1][j];
                int rightd = matrix[i][j]; 
                if(j+1 < n) rightd += dp[i-1][j+1];
                else rightd += 1e8;
                dp[i][j] = min(leftd ,min(below, rightd));
            }
        }
        
        for(int j=0; j<n; j++){
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};