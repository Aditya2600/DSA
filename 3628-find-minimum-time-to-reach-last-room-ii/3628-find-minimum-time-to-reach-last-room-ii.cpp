class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int dx[] = {+1, -1, 0, 0};
        int dy[] = {0, 0, +1, -1};
        
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<vector<int>>> dist(n, vector<vector<int>> (m,vector<int> (2, INT_MAX)));
        set<tuple<int, int, int, int>> q;
        q.insert({0, 0, 0, 0});
        dist[0][0][0] = 0;

        while(!q.empty()){
            auto[distance, x, y, move] = *q.begin();
            int cost = ((move ^ 1) ? 1 : 2);
            q.erase(*q.begin());
            for(int i=0; i<4; i++){
                int X = x + dx[i];
                int Y = y + dy[i];
                if(X >= 0 && X < n && Y >= 0 && Y < m && dist[X][Y][move^1] > max(dist[x][y][move] + cost, moveTime[X][Y] + cost)){
                    q.erase({dist[X][Y][move^1], X, Y, (move^1)});
                    dist[X][Y][move^1] = max(dist[x][y][move] + cost, moveTime[X][Y] + cost);
                    q.insert({dist[X][Y][move^1], X, Y, (move^1)});
                }
            }
        };
        return min(dist[n-1][m-1][0], dist[n-1][m-1][1]); 
    }
};