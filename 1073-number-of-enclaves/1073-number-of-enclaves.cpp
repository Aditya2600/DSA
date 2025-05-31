class Solution {
public:
    
    vector<vector<bool>> vis;
    int bfs(int x, int y, vector<vector<int>>& grid){
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        q.push({x, y});
        vis[x][y] = true;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int walks = 1;
        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];               
                if(nr < n && nr >= 0 && nc < m && nc >= 0 && grid[nr][nc] == 1 && !vis[nr][nc]){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                    walks++;
                }
                
            }
        }
        return walks;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vis.resize(n, vector<bool> (m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && (i == 0 || i == n-1 || j == 0 || j == m-1) && !vis[i][j]){
                    ans += bfs(i, j, grid);
                }
            }
        }
        int cnt1 = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    cnt1++;
                }
            }
        }
        return cnt1 - ans;
    }
};