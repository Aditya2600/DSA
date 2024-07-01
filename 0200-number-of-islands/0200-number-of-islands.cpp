class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int cc = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c] == '0'){
                    continue;
                }
                cc++;
                grid[r][c] = '0';
                queue<pair<int,int>> qu;
                qu.push({r,c});
                while(not qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    if(currRow - 1 >= 0 and grid[currRow-1][currCol] == '1'){
                        qu.push({currRow-1,currCol});
                        grid[currRow - 1][currCol] = '0';
                    }
                    if(currRow + 1 < rows and grid[currRow+1][currCol] == '1'){
                        qu.push({currRow+1,currCol});
                        grid[currRow + 1][currCol] = '0';
                    }
                    if(currCol - 1 >= 0 and grid[currRow][currCol-1] == '1'){
                        qu.push({currRow,currCol-1});
                        grid[currRow][currCol-1] = '0';
                    }
                    if(currCol + 1 < cols and grid[currRow][currCol+1] == '1'){
                        qu.push({currRow,currCol+1});
                        grid[currRow][currCol+1] = '0';
                    }                             
                }          
            }
        }
        return cc;
    }
};