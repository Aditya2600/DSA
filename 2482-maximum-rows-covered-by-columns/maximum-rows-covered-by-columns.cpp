class Solution {
public:
    int ans = 0;

    int covered(vector<vector<int>>& mat){
        int cnt = 0;
        for(int i = 0; i < mat.size(); i++){
            bool flag = true;
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }

    int solve(vector<vector<int>>& matrix, int col, int i){
        if(i == matrix[0].size() || col == 0){
            int c = covered(matrix);
            ans = max(ans, c);
            return ans;
        }

        // don't take current column
        int notTakeCol = solve(matrix, col, i+1);

        // take current column
        vector<vector<int>> cmat = matrix;
        for(int j = 0; j < matrix.size(); j++){
            cmat[j][i] = 0;
        }
        int takeCol = solve(cmat, col-1, i+1);

        return max(notTakeCol, takeCol);
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        solve(matrix, numSelect, 0);
        return ans;
    }
};