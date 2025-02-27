class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        for(int col=1; col<n; col++){
            sortAsc(grid, 0, col);
        }
        for(int row=0; row<n; row++){
            sortDesc(grid, row, 0);
        }
        return grid;
    }
    void sortAsc(vector<vector<int>>& grid, int row, int col){
        int r = row;
        int c = col;
        int n = grid.size();

        vector<int> diagonal;
        while(r < n && c < n){
            diagonal.push_back(grid[r++][c++]);
        }
        sort(diagonal.begin(), diagonal.end());

        int i = 0;
        while(row < n && col < n){
            grid[row++][col++] = diagonal[i++];
        }
    }
    void sortDesc(vector<vector<int>>& grid, int row, int col){
        int r = row;
        int c = col;
        int n = grid.size();
        vector<int> diagonal;
        while(r < n && c < n){
            diagonal.push_back(grid[r++][c++]);
        }
        sort(diagonal.begin(), diagonal.end());
        reverse(diagonal.begin(), diagonal.end());
        
        int i = 0;
        while(row < n && col < n){
            grid[row++][col++] = diagonal[i++];
        }
    }
};