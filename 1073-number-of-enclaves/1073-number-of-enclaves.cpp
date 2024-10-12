class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> qu;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (grid[i][j] == 1 && vis[i][j] == 0) {
                        qu.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, +1, 0, -1};
        while (!qu.empty()) {
            int row = qu.front().first;
            int col = qu.front().second;
            qu.pop();

            for (int i = 0; i < 4; i++) {
                int newr = row + delrow[i];
                int newc = col + delcol[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    grid[newr][newc] == 1 && vis[newr][newc] == 0) {
                    qu.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1 && vis[i][j] == 0) {
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };