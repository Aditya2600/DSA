class Solution {
public:
    long long mod = 1e9 + 7;
    int n, LOG;
    vector<vector<int>> par;
    vector<int> depth;
    vector<int> pow2;
    vector<vector<int>> neigh;

    void dfs(int node, int parent){
        par[node][0] = parent;
        for(int k=1; k<LOG; ++k){
            if (par[node][k-1] != -1){
                par[node][k] = par[par[node][k-1]][k-1];
            }
            else{
                par[node][k] = -1; 
            }
        }
        for(auto v : neigh[node]){
            if(v != parent){
                depth[v] = depth[node] + 1;
                dfs(v, node);
            }
        }
    }
    int lca(int u, int v){
        if(depth[u] < depth[v]){
            swap(u, v);
        }
        for(int i=LOG-1; i>=0; --i){
            if((depth[u] - depth[v]) & (1<<i)){
                u = par[u][i];
            }
        }
        if(u == v) return u;
        for(int i=LOG-1; i>=0; i--){
            if(par[u][i] != par[v][i]){
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    }
    
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        n = edges.size() + 1;
        LOG = 1;
        while((1 << LOG) <= n){
            ++LOG;
        }
        neigh.assign(n+1, {});
        for(auto& e : edges){
            int u = e[0], v = e[1];
            neigh[u].push_back(v);
            neigh[v].push_back(u);
        }
        par.assign(n + 1, vector<int>(LOG, -1));
        depth.assign(n + 1, 0);
        dfs(1, -1);

        pow2.resize(n);
        pow2[0] = 1;
        for(int i=1; i<n; ++i){
            pow2[i] = (pow2[i-1] << 1) % mod;
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for(auto& q:queries){
            int u = q[0], v = q[1];
            if(u == v){
                ans.push_back(0);
                continue;
            }
            int w = lca(u, v);
            int L = depth[u] + depth[v] - 2*depth[w];
            ans.push_back(pow2[L - 1]);
        }
        return ans;
    }
};