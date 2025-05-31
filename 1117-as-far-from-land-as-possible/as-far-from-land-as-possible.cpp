class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }
        if (q.empty() || q.size() == n * m) {
            return -1;
        }
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        int maxDist = -1;
        while (!q.empty()) {
            int size = q.size();
            maxDist++;
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && nx < m &&
                        grid[nx][ny] == 0) {
                        grid[nx][ny] = -1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return maxDist;
    }
};