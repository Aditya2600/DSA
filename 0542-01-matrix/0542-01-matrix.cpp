class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>> qu;
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> dis(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    qu.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else vis[i][j] = 0;
            }
        }
    
    int delRow[] = {-1,0,+1,0};
    int delCol[] = {0,+1,0,-1};
    while(!qu.empty()){
        int row = qu.front().first.first;
        int col = qu.front().first.second;
        int steps = qu.front().second;
        qu.pop();
        dis[row][col] = steps;
        for(int d=0; d<4; d++){
            int nrow = row + delRow[d];
            int ncol = col + delCol[d];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                qu.push({{nrow,ncol},steps + 1});
            }
        }
    }
    return dis;
    }
};