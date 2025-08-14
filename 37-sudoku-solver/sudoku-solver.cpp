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
    int row[9] = {0}, col[9] = {0}, box[3][3] = {0};

public:
    bool backtrack(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;
        if (j == 9)
            return backtrack(board, i + 1, 0);

        if (board[i][j] != '.')
            return backtrack(board, i, j + 1);
        for (int num = 1; num <= 9; num++) {
            int mask = 1 << num;
            if (!(row[i] & mask) && !(col[j] & mask) &&
                !(box[i / 3][j / 3] & mask)) {
                board[i][j] = num + '0';
                row[i] |= mask;
                col[j] |= mask;
                box[i / 3][j / 3] |= mask;

                if (backtrack(board, i, j + 1))
                    return true;

                board[i][j] = '.';
                row[i] &= ~mask;
                col[j] &= ~mask;
                box[i / 3][j / 3] &= ~mask;
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int mask = 1 << num;
                    row[i] |= mask;
                    col[j] |= mask;
                    box[i / 3][j / 3] |= mask;
                }
            }
        }
        backtrack(board, 0, 0);
    }
};