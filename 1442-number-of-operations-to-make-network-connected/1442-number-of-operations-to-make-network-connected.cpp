class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = parent[ulp_u];
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];  // Corrected: should update size of ulp_v
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtras = 0; // Count of redundant connections
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            // Check if u and v are already connected
            if (ds.findUPar(u) == ds.findUPar(v)) {
                cntExtras++; // This connection is extra
            } else {
                ds.unionBySize(u, v); // Connect u and v
            }
        }
        
        // Count how many connected components are there
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) {
                cntC++;
            }
        }

        // We need cntC - 1 connections to connect all components
        int ans = cntC - 1;
        // If we have enough extra connections, we can connect all components
        if (cntExtras >= ans) {
            return ans;
        }

        return -1; // Missing semicolon fixed
    }
};
