class Solution {
public:
    long long mod = 1e9 + 7;
    vector<vector<int>> adj;
    vector<int> vis;

    // DFS to find max depth from node 0
    int dfs(int node) {
        vis[node] = 1;
        int maxDepth = 0;
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                maxDepth = max(maxDepth, 1 + dfs(neighbor));
            }
        }
        return maxDepth;
    }
    long long modExp(int a, long long b) {
        long long ans = 1;
        while (b > 0) {
            if (b & 1) {
                ans = (ans * a) % mod;
            }
            a = (1LL * a * a) % mod;
            b >>= 1;
        }
        return ans;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adj.resize(n);
        vis.resize(n, 0);

        // Build undirected adjacency list
        for (auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = dfs(0); // root at node 0

        if (maxDepth == 0)
            return 0; // no path, single node

        // Return 2^(maxDepth - 1) % mod
        return modExp(2, maxDepth - 1);
    }
};