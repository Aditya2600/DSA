class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) return grid[0][0] == 0 ? 1 : -1;
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        vector<vector<int>> dis(n, vector<int>(m,INT_MAX));
        q.push({1,{0,0}});
        dis[0][0] = 1;
        int delRow[] = {+1,0,-1,0,+1,-1,+1,-1};
        int delCol[] = {0,+1,0,-1,+1,-1,-1,+1};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int dist = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;
            for(int d = 0; d<8; d++){
                int newRow = r + delRow[d];
                int newCol = c + delCol[d];
                if(newRow >= 0 && newRow < n && newCol >=0 && newCol < m && grid[newRow][newCol] == 0 && dis[newRow][newCol] > dist + 1){
                    dis[newRow][newCol] = 1 + dist;
                    if(newRow == n-1 && newCol == m-1) return dist+1;
                    q.push({1+dist,{newRow,newCol}});
                }
            }
        }
        return -1;
    }
};