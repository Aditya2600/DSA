// class Solution {
// public:
//     void dfs(vector<vector<int>>& stones, int index, vector<bool>& vis){
//         vis[index] = true;
//         for(int i=0; i<stones.size(); i++){
//             int r = stones[index][0];
//             int c = stones[index][1];

//             if(vis[i] == false && (stones[i][0] == r || stones[i][1] == c)){
//                 dfs(stones, i, vis);
//             }
//         }

//     }
//     int removeStones(vector<vector<int>>& stones) {
//         int n = stones.size();

//         vector<bool> vis(n, false);

//         int group = 0;
//         for(int i=0; i<n; i++){
//             if(vis[i] == true){
//                 continue;
//             }
//             dfs(stones, i, vis);
//             group++;
//         }
//         return n - group;
//     }
// };
class Solution {
public:
    int n;
    vector<int> parent, rankv;

    int findUPar(int x){
        if(parent[x] == x) return x;
        return parent[x] = findUPar(parent[x]);
    }

    void Union(int u, int v){
        int pu = findUPar(u);
        int pv = findUPar(v);
        if(pu == pv) return;

        if(rankv[pu] < rankv[pv]){
            parent[pu] = pv;
        }
        else if(rankv[pu] > rankv[pv]){
            parent[pv] = pu;
        }
        else{
            parent[pv] = pu;
            rankv[pu]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        parent.resize(n);
        rankv.resize(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(stones[i][0] == stones[j][0] ||
                   stones[i][1] == stones[j][1]){
                    Union(i, j);
                }
            }
        }

        int groups = 0;
        for(int i = 0; i < n; i++){
            if(findUPar(i) == i){
                groups++;
            }
        }

        return n - groups;
    }
};