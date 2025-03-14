#include <iostream>
#include <vector>
using namespace std;

vector<int> prefix;
vector<vector<pair<int, int>>> neigh;
vector<vector<int>> parent;
vector<int> depth;

void dfs(int node, int dep, int par, int val) {
    parent[node][0] = par;  // Store parent for LCA
    depth[node] = dep;
    prefix[node] = val + (par == -1 ? 0 : prefix[par]);

    for (auto v : neigh[node]) {
        if (v.first != par) {
            dfs(v.first, dep + 1, node, v.second);
        }
    }
}

// Function to compute LCA using Binary Lifting
int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int LOG = parent[0].size();
    // Bring u and v to the same depth
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - depth[v] >= (1 << i)) {
            u = parent[u][i];
        }
    }

    if (u == v) return u;

    // Move both nodes up until we find LCA
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

// Function to get path sum between two nodes
int getSum(int u, int v) {
    return prefix[u] + prefix[v] - 2 * prefix[lca(u, v)];
}

int main() {
    int n;
    cin >> n;
    neigh.resize(n);
    prefix.resize(n, 0);
    depth.resize(n, 0);
    parent.assign(n, vector<int>(20, -1));  // Assuming log(n) ≤ 20

    // Read tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;  // u - v edge with weight w
        neigh[u].push_back({v, w});
        neigh[v].push_back({u, w});
    }

    // Perform DFS from root (assuming node 0 as root)
    dfs(0, 0, -1, 0);

    // Answer queries
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << "Sum of path from " << u << " to " << v << " is: " << getSum(u, v) << endl;
    }

    return 0;
}