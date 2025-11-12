class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 2;
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    q.push({nr, nc});
                    grid[nr][nc] = 2;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int land = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && (i == 0 || i == n-1 || j == 0 || j == m-1)){
                    bfs(i, j, grid);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    land++;
                }
            }
        }
        return land;
    }
};