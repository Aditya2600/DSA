class Solution {
public:
    vector<vector<bool>> vis;
    void bfs(int node1, int node2, vector<vector<int>>& grid, int value){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({node1, node2});
        vis[node1][node2] = true;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == value && vis[nx][ny] == false){
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vis.resize(n, vector<bool> (m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0 && (i == n-1 || i == 0 || j == m-1 || j == 0) && vis[i][j] == false){
                    bfs(i, j, grid, 0);
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    bfs(i, j, grid, 1);
                }
            }
        }
        int ans = 0;
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    bfs(i, j, grid, 0);
                    ans++;
                }
            }
        }
        return ans;
    }
};