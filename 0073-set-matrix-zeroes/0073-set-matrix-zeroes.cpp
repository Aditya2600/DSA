class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int,int>> q;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int col = 0; col<m; col++){
                matrix[r][col] = 0;
            }
            for(int row = 0; row<n; row++){
                matrix[row][c] = 0;
            }
        }
    }
};