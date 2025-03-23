class Solution {
public:
    void dfs(int u, vector<vector<int>>& gr, vector<bool>& vis, int& nodes,
             int& degreeSum) {
        vis[u] = true;
        nodes++;
        degreeSum += gr[u].size();
        for (int v : gr[u]) {
            if (!vis[v])
                dfs(v, gr, vis, nodes, degreeSum);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> gr(n);
        for (auto& e : edges) {
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i])
                continue;
            int nodes = 0, degreeSum = 0;
            dfs(i, gr, vis, nodes, degreeSum);
            if (degreeSum == nodes * (nodes - 1))
                ans++;
        }
        return ans;
    }
};