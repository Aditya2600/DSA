class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void Union(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);

        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = parent[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }

        if(connections.size() < n - 1){
            return -1;
        }
        int components = n;
        for(auto& vec : connections){
            if(find(vec[0]) != find(vec[1])){
                Union(vec[0], vec[1]);
                components--;
            }
        }
        return components - 1;
    }
};