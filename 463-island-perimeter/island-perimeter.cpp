class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> qu;
        vector<pair<int, int>> directions = {
            {-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    qu.push({i, j});
                    vis[i][j] = true;
                    goto bfs_start;
                }
            }
        }
    bfs_start:
        int peri = 0;
        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m ||
                    grid[nx][ny] == 0) {
                    peri++;
                } else if (!vis[nx][ny]) {
                    vis[nx][ny] = true;
                    qu.push({nx, ny});
                }
            }
        }
        return peri;
    }
};
