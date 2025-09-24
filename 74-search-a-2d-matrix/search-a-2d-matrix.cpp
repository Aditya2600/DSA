// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(int i=0; i<matrix.size(); i++){
//             for(int j=matrix[0].size() - 1; j >= 0; j--){
//                 if(matrix[i][j] == target){
//                     return true;
//                 }
//                 if(matrix[i][j] < target){
//                     break;
//                 }
//             }
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int lo = 0, hi = n * m - 1;
        
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int row = mid / m;
            int col = mid % m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return false;
    }
};