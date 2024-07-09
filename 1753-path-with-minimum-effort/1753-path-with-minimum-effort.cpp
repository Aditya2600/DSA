class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        
        pq.push({0,{0,0}});
        
        dist[0][0] = 0;
        int delr[] = {+1,0,-1,0};
        int delc[] = {0,+1,0,-1};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int row = curr.second.first;
            int col = curr.second.second;
            int h = curr.first;
            if(row == n-1 && col == m-1) return h;
            for(int d=0; d<4; d++){
                int nr = row + delr[d];
                int nc = col + delc[d];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m){
                    int newEffort = max(abs(heights[nr][nc]-heights[row][col]),h);
                    if(newEffort < dist[nr][nc]){
                        dist[nr][nc] = newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};