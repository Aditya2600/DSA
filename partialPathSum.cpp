#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 100005; // Adjust according to problem constraints
const int LOG = 20;

vector<int> neigh[MAXN];
int par[MAXN][LOG], depth[MAXN], partial[MAXN];

void dfs(int node, int prev, int dep) {
    par[node][0] = prev;
    depth[node] = dep;
    
    for (int i = 1; i < LOG; i++) {
        if (par[node][i - 1] != -1) { // Ensure valid access
            par[node][i] = par[par[node][i - 1]][i - 1];
        } else {
            par[node][i] = -1; // Mark as invalid
        }
    }

    for (auto v : neigh[node]) {
        if (v != prev) {
            dfs(v, node, dep + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    for (int i = LOG - 1; i >= 0; i--) {
        if ((depth[u] - depth[v]) & (1 << i)) {
            u = par[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--) {
        if (par[u][i] != -1 && par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

void addX(int u, int v, int x) {
    partial[v] += x;
    partial[u] += x;
    int lc = lca(v, u);
    partial[lc] -= x;
    if (par[lc][0] != -1) { // Ensure valid parent before subtraction
        partial[par[lc][0]] -= x;
    }
}

void pushAll(int node, int pp) {
    for (auto v : neigh[node]) {
        if (v != pp) {
            pushAll(v, node);
        }
    }
    if (par[node][0] != -1) { // Ensure parent exists
        partial[par[node][0]] += partial[node];
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }

    // Initialize LCA structure
    dfs(1, -1, 0);

    return 0;
}
