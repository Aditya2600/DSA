void addX(int u, int v, int x){
    partial[v] += x;
    partial[u] += x;
    int lc = lca(v, u);
    partial[lc] -= x;
    par[partial[lc][0]] -= x;
}
void pushAll(int node, int pp){
    for(auto v : neigh[node]){
        if(v != pp){
            pushAll(v, node);
        }
    }
    partial[par[node][0]] += partial[node];
}