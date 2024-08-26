class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
              int n = matrix.size();    // Number of rows
        int m = matrix[0].size(); // Number of columns
        int col0 = 1;             // Variable to track if the first column should be zeroed

        // Step 1: Mark rows and columns that need to be zeroed
        for(int i = 0; i < n; i++) {
            if(matrix[i][0] == 0) col0 = 0;  // If any cell in the first column is zero, mark col0
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // Mark the first cell of the row
                    matrix[0][j] = 0;  // Mark the first cell of the column
                }
            }
        }

        // Step 2: Use the marks to set the appropriate cells to zero
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle the first row
        if(matrix[0][0] == 0) {
            for(int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle the first column
        if(col0 == 0) {
            for(int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};