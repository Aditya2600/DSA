class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<string>> result;
    // bool canPlaceQueen(int row, int col, int n){
    //     for(int i=row-1; i>=0; i--){
    //         if(grid[i][col] == 'Q'){
    //             return false;
    //         }
    //     }
    //     for(int i=row-1, j=col-1; i>=0 and j>=0; i--, j--){
    //         if(grid[i][j] == 'Q'){
    //             return false;
    //         }
    //     }
    //     for(int i=row-1, j=col+1; i>=0 and j<n; i--, j++){
    //         if(grid[i][j] == 'Q'){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    void f(int row, int n, int colMask, int ld_mask, int rd_mask){
        if(row == n){
            vector<string> temp;
            for(int i=0; i<n; i++){
                string res = "";
                for(int j=0; j<n; j++){
                    res += grid[i][j];
                }
                temp.push_back(res);
            }
            result.push_back(temp);
            return;
        }
        
        for(int col=0; col<n; col++){
            int colBit = 1<<col;
            int ldBit = 1<<(row-col+n-1);
            int rdBit = 1<<(row+col);
            if((colMask & colBit) == 0 && (rd_mask & rdBit) == 0 and (ld_mask & ldBit) == 0){
                grid[row][col] = 'Q';
                f(row+1, n, colMask|colBit, ld_mask|ldBit, rd_mask|rdBit);
                grid[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        grid.resize(n, vector<char> (n, '.'));
        f(0, n, 0, 0, 0);
        return result;
    }
};