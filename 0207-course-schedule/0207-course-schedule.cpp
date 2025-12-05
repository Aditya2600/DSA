class Solution {
private:
    // DFS returns true if cycle is found
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;          // node is in current recursion path

        for (auto it : adj[node]) {
            // FIX: yahan !vis[node] nahi, !vis[it] hoga
            if (!vis[it]) {
                if (dfs(it, vis, pathVis, adj)) return true;   // cycle in child
            }
            // if child is already in current path -> cycle
            else if (pathVis[it]) {
                return true;
            }
        }

        pathVis[node] = 0;          // backtrack
        return false;               // no cycle from this node
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &it : prerequisites) {
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);    // u -> v
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        // har component ke liye DFS chalao
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) {
                    // cycle mila -> saare courses finish nahi ho sakte
                    return false;
                }
            }
        }
        // no cycle -> all courses can be finished
        return true;
    }
};