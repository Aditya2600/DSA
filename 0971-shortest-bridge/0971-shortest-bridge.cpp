class Solution {
    private:
    void dfs(vector<vector<int>> &grid,vector<vector<bool>> &vis, queue<pair<int,int>> &qu, int i, int j, vector<vector<int>> &dir){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j>=m || j<0 || vis[i][j] || grid[i][j] == 0){
            return;
        }
        vis[i][j] = true;
        qu.push({i,j});
        for(auto &d : dir){
            dfs(grid,vis,qu,i+d[0],j+d[1],dir);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        queue<pair<int,int>> qu;
        bool found = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    dfs(grid,vis,qu,i,j,dir);
                    found = true;
                    break;
                }
            }
            if(found) break;
        }
        int step = 0;
        while(!qu.empty()){
            int size = qu.size();
            while(size--){
                auto curr = qu.front();
                qu.pop();
                for(auto &di : dir){
                    int i = curr.first + di[0];
                    int j = curr.second + di[1];
                    if(i>=0 && j>=0 && i<n && j<m && !vis[i][j]){
                        if(grid[i][j] == 1){
                            return step;
                        }
                        qu.push({i,j});
                        vis[i][j] = true;
                    }
                }           
                }
                step++;
            }
            return -1;
        }
};    