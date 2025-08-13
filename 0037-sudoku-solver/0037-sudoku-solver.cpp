// class Solution {
// public:
//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }

//     bool solve(vector<vector<char>>& board){
//         for(int i=0; i<board.size(); i++){
//             for(int j=0; j<board[0].size(); j++){
//                 if(board[i][j] == '.'){
//                     for(char c = '1';  c <= '9'; c++){
//                         if(isValid(board, c, i, j)){
//                             board[i][j] = c;
//                             if(solve(board) == true){
//                                 return true;
//                             }
//                             else{
//                                 board[i][j] = '.';
//                             }
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
//         return true;
//     }

//     bool isValid(vector<vector<char>>& board, char& c, int row, int col){
//         for(int i=0; i<9; i++){
//             if(board[i][col] == c){
//                 return false;
//             }
//             else if(board[row][i] == c){
//                 return false;
//             }
//             else if(board[3 * (row/3) + i/3][3 * (col/3) + i%3] == c){
//                 return false;           
//             }
//         }
//         return true;
//     }
// };
class Solution {
    int rows[9] = {0}, cols[9] = {0}, boxes[3][3] = {0};
    
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        // If we reached the end of the board, puzzle is solved
        if (i == 9) return true;
        
        // Move to next row if column ends
        if (j == 9) return backtrack(board, i + 1, 0);
        
        // Skip already filled cells
        if (board[i][j] != '.') return backtrack(board, i, j + 1);
        
        for (int num = 1; num <= 9; num++) {
            int mask = 1 << num;
            if (!(rows[i] & mask) && !(cols[j] & mask) && !(boxes[i/3][j/3] & mask)) {
                // Place number
                board[i][j] = '0' + num;
                rows[i] |= mask;
                cols[j] |= mask;
                boxes[i/3][j/3] |= mask;
                
                if (backtrack(board, i, j + 1)) return true;
                
                // Backtrack
                board[i][j] = '.';
                rows[i] ^= mask;
                cols[j] ^= mask;
                boxes[i/3][j/3] ^= mask;
            }
        }
        return false; // No valid number possible
    }
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        // Pre-fill bitmasks from the given board
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int mask = 1 << num;
                    rows[i] |= mask;
                    cols[j] |= mask;
                    boxes[i/3][j/3] |= mask;
                }
            }
        }
        backtrack(board, 0, 0);
    }
};