class Solution {
private:
    // DFS traversal that works directly on the isConnected matrix
    void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[node] = 1;  // Mark the node as visited
        for (int j = 0; j < isConnected.size(); j++) {
            // If there is a direct connection and the node is not visited, visit it
            if (isConnected[node][j] == 1 && !vis[j]) {
                dfs(j, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();  // Number of nodes (cities)
        vector<int> vis(v, 0);  // To keep track of visited nodes
        int cnt = 0;  // Count the number of connected components (provinces)

        // Perform DFS traversal for each unvisited node
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {  // If node i is not visited, it's a new component
                cnt++;
                dfs(i, isConnected, vis);  // Visit all nodes in this component
            }
        }

        return cnt;  // Return the number of provinces (connected components)
    }
};
