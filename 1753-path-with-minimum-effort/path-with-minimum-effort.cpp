class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int ,pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> dis(n, vector<int> (m, 1e9));
        pq.push({0, {0, 0}});
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            int h = pq.top().first;
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            pq.pop();
            if(r == n-1 && c == m-1){
                return h;
            }
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < n && nr >= 0 && nc < m && nc >= 0){
                    int newEffort = max(h, abs(heights[nr][nc] - heights[r][c]));
                    if(newEffort < dis[nr][nc]){
                        dis[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};