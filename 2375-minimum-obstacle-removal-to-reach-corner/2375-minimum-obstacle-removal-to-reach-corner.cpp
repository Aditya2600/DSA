class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {
            {+1, 0}, {0, +1}, {-1, 0}, {0, -1}};
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            pq;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> minObstacles(n, vector<int>(m, INT_MAX));
        minObstacles[0][0] = grid[0][0];
        pq.push({minObstacles[0][0], 0, 0});
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int obstacles = curr[0], row = curr[1], col = curr[2];
            if (row == n - 1 && col == m - 1) {
                return obstacles;
            }
            for (auto [a, b] : directions) {
                int nr = a + row, nc = b + col;

                if (nr >= 0 && nc >= 0 && nr < n && nc < m) {
                    int newObstacles = obstacles + grid[nr][nc];

                    if (newObstacles < minObstacles[nr][nc]) {
                        minObstacles[nr][nc] = newObstacles;
                        pq.push({newObstacles, nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};