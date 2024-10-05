class Solution {
public:
bool isPossible(vector<vector<int>>& grid,int mid){
    if(grid[0][0]>mid)return false;

    queue<pair<int,int>> q;
    vector<vector<int>> vis(grid.size(),vector<int>(grid.size(),0));
    q.push({0,0});
    vis[0][0]=1;
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(x==grid.size()-1 && y==grid[0].size()-1)return true;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size() || grid[nx][ny]>mid || vis[nx][ny]==1)continue;
                q.push({nx,ny});
                vis[nx][ny]=1;
            }
        }
    }
    return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        int l=0;
        int h=INT_MAX;
        int n=grid.size();
        // binary search on time
        while(l<h){
            int mid=l+(h-l)/2;
            if(isPossible(grid,mid)){
                h=mid;
            }
            else  l=mid+1;
        }
        return h;
    }
};