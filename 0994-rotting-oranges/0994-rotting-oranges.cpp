class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int, int>>> qu;
        int fresh = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    qu.push({0, {i, j}});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int dr[] = {+1, 0, -1, 0};
        int dc[] = {0, +1, 0, -1};

        int ans = 0;

        while(!qu.empty()){
            auto front = qu.front();
            qu.pop();
            int r = front.second.first;
            int c = front.second.second;
            int t = front.first;

            ans = max(ans, t);

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    fresh--;
                    qu.push({t+1, {nr, nc}});
                }
            }
        }
        if(fresh > 0) return -1;
        return ans;
    }
};