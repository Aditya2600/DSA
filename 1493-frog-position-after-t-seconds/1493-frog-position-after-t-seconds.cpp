class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
         vector<vector<int>> graph(n + 1);
        
        // Build graph from edge list
        // Each edge connects two vertices (undirected)
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            // Add v to u's list
            graph[u].push_back(v);
            // Add u to v's list because tree is undirected
            graph[v].push_back(u);
        }
        
        // visited vector to ensure we do not revisit vertices
        vector<bool> visited(n + 1, false);
        
        // Start DFS from vertex 1 with probability 1.0 and given time t
        return dfs(1, t, target, graph, visited);
    }
    
private:
    // Helper function which performs DFS
    double dfs(int node, int t, int target, vector<vector<int>>& graph, vector<bool>& visited) {
        // Mark the current node as visited
        visited[node] = true;
        
        // Base condition: if time is 0, or if the current node is a leaf (all neighbors visited)
        // then if we are at the target, return probability 1, else 0.
        if (t == 0) {
            // No more time to jump: if the node is target, it's valid; otherwise not.
            return (node == target) ? 1.0 : 0.0;
        }
        
        // Count the number of unvisited adjacent vertices
        int unvisitedCount = 0;
        for (int child : graph[node]) {
            if (!visited[child])
                unvisitedCount++;
        }
        
        // If no unvisited children exist, frog stays on current node indefinitely.
        // In such case, if this node is the target, then probability remains 1
        // regardless of remaining time; else, probability is 0.
        if (unvisitedCount == 0) {
            return (node == target) ? 1.0 : 0.0;
        }
        
        // Initialize probability for the current node as 0
        double resultProbability = 0.0;
        // Traverse each unvisited neighbor and call DFS recursively reducing time by 1
        for (int child : graph[node]) {
            if (!visited[child]) {
                // Recursive call for child with updated probability and time reduced by 1
                // The frog jumps with probability 1/unvisitedCount to each adjacent vertex
                double childProbability = dfs(child, t - 1, target, graph, visited);
                resultProbability += (childProbability / unvisitedCount);
            }
        }
        
        // Return the cumulative result probability from current node to reach target
        return resultProbability;
    }
};