#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
const int LOG = 20;

vector<int> neigh[MAXN];
int par[MAXN][LOG], depth[MAXN];

void dfs(int node, int prev, int dep) {
    par[node][0] = prev;
    depth[node] = dep;

    // Precompute ancestors using Binary Lifting
    for (int i = 1; i < LOG; i++) {
        if (par[node][i - 1] != -1)
            par[node][i] = par[par[node][i - 1]][i - 1];
        else
            par[node][i] = -1;
    }

    for (auto v : neigh[node]) {
        if (v != prev) {
            dfs(v, node, dep + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    // Bring u and v to the same depth
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            u = par[u][i];
        }
    }

    if (u == v) return u;

    // Move both nodes up until we find LCA
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

int main() {
    int n;
    cin >> n;  // Number of nodes

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < LOG; j++) {
            par[i][j] = -1;
        }
    }

    // Input edges for the tree
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }

    // Run DFS to initialize Binary Lifting table
    dfs(0, -1, 0); // Assuming root is node 0

    // Query LCA
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << "LCA of " << u << " and " << v << " is: " << lca(u, v) << endl;
    }

    return 0;
}