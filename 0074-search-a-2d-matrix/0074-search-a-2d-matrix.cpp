class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            for(int j=matrix[0].size() - 1; j >= 0; j--){
                if(matrix[i][j] == target){
                    return true;
                }
                if(matrix[i][j] < target){
                    break;
                }
            }
        }
        return false;
    }
};