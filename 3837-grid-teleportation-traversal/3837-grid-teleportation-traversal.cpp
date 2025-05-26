class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector occ(26, vector<array<int, 2>> ());
        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] >= 'A' && matrix[i][j] <= 'Z'){
                    occ[matrix[i][j] - 'A'].push_back({i, j});
                }
            }
        }
        vector dist(n, vector(m, n*m));
        vector<int> vis(n * m + 26, 0);
        deque<array<int, 2>> q;

        dist[0][0] = 0;
        q.push_back({0, 0});

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop_front();

            if(vis[r * m + c]) continue;
            vis[r * m + c] = 1;

            if(matrix[r][c] >= 'A' && matrix[r][c] <= 'Z' && !vis[n*m + (matrix[r][c] - 'A')]){
                vis[n * m + matrix[r][c] - 'A'] = 1;
                for(auto [x, y] : occ[matrix[r][c] - 'A']){
                    if(dist[x][y] <= dist[r][c]) continue;
                    dist[x][y] = dist[r][c];
                    q.push_front({x, y});
                }
            }
            for(int i=0; i<4; i++){
                int x = r + dx[i], y = c + dy[i];
                if(x < 0 || y < 0 || x >= n || y >= m || matrix[x][y] == '#') continue;
                if(dist[x][y] <= dist[r][c] + 1) continue;
                dist[x][y] = dist[r][c] + 1;
                q.push_back({x, y});
            }
        }
        return dist[n-1][m-1] == n*m ? -1 : dist[n-1][m-1];
    }
};