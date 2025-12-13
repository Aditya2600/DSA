class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> grid(n, vector<int> (n, 1e8));
        for(int i=0; i<edges.size(); i++){
            grid[edges[i][0]][edges[i][1]] = edges[i][2];
            grid[edges[i][1]][edges[i][0]] = edges[i][2]; 
        }
        for(int i=0; i<n; i++){
            grid[i][i] = 0;
        }
        for(int via = 0; via < n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][via] != 1e8 && grid[via][j] != 1e8){
                        grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
                    }
                }
            }
        }
        
        int mincnt = n;
        int city = n;
        for(int i=n-1; i>=0; i--){
            int cnt = 0;
            for(int j=n-1; j>=0; j--){
                if(grid[i][j] != 1e8 && grid[i][j] != 0 && grid[i][j] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt < mincnt){
                mincnt = cnt;
                city = i;
            }
        }
        return city;
    }
};