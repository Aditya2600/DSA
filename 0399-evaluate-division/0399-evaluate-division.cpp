class Solution {
public:
    void dfs(string src, string dst, vector<vector<string>>& queries,
             unordered_set<string>& vis, unordered_map < string,
             vector < pair < string, double >>> &adj, double& ans, double product) {
        if (vis.find(src) != vis.end()) {
            return;
        }
        vis.insert(src);
        if (src == dst) {
            ans = product;
            return;
        }
        for (auto& p : adj[src]) {
            string v = p.first;
            double val = p.second;
            dfs(v, dst, queries, vis, adj, ans, product*val);
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map < string, vector < pair < string, double >>> adj;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];
            adj[u].push_back({v, val});
            adj[v].push_back({u, 1.0 / val});
        }
        vector<double> result;
        for (auto& query : queries) {
            string src = query[0];
            string dst = query[1];
            double ans = -1.0;
            double product = 1.0;
            if (adj.find(src) != adj.end()) {
                unordered_set<string> vis;
                dfs(src, dst, queries, vis, adj, ans, product);
            }
            result.push_back(ans);
        }
        return result;
    }
};