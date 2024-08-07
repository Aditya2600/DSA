class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mini = 1e8;
        vector<int> prev(n,0), curr(n,0);
        for(int j=0; j<n; j++){
            prev[j] = matrix[0][j];
        }
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int leftd = matrix[i][j];
                if(j-1>=0) leftd += prev[j-1];
                else leftd += 1e8;
                int below = matrix[i][j] + prev[j];
                int rightd = matrix[i][j]; 
                if(j+1 < n) rightd += prev[j+1];
                else rightd += 1e8;
                curr[j] = min(leftd ,min(below, rightd));
            }
            prev = curr;
        }
        
        for(int j=0; j<n; j++){
            mini = min(mini, prev[j]);
        }
        return mini;
    }
};