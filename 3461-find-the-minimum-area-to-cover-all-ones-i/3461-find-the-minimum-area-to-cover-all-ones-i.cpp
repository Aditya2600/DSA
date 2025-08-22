class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int area = 1;
        int minRow = grid.size(), maxRow = 0;
        int minCol = grid[0].size(), maxCol = 0;
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
                else continue;
            }
        }
        if(minRow == grid.size() || minCol == grid[0].size()){
            return 1;
        }
        else{
            int height = maxRow - minRow + 1;
            int width = maxCol - minCol + 1;
            area = height * width;
        }
        return  area;
    }
};