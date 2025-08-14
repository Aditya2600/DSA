// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         queue<pair<int,int>> q;
//         int n = matrix.size();
//         int m = matrix[0].size();
//         for(int i=0; i<n; i++){
//             for(int j=0; j<m; j++){
//                 if(matrix[i][j] == 0){
//                     q.push({i, j});
//                 }
//             }
//         }
//         while(!q.empty()){
//             auto [r, c] = q.front();
//             q.pop();
//             for(int col = 0; col<m; col++){
//                 matrix[r][col] = 0;
//             }
//             for(int row = 0; row<n; row++){
//                 matrix[row][c] = 0;
//             }
//         }
//     }
// };
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(n, 0),col(m, 0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};