class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. Build adjacency list for efficient neighbor access
        vector<vector<pair<int, int>>> adj(n); // Use vector<pair<int, int>> for clarity
        for (auto& edge : times) {
            int u = edge[0] - 1; // Adjust indices for 0-based indexing
            int v = edge[1] - 1;
            int w = edge[2];
            adj[u].push_back({v, w});
        }

        // 2. Initialize distances and priority queue
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0; // Start from source node k (adjust for 0-based indexing)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k - 1}); // Push initial node with distance 0

        // 3. Dijkstra's algorithm for finding shortest paths
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int time = curr.first;
            int source = curr.second;

            // 4. Optimization: Skip visited nodes
            if (dist[source] < time) {
                continue;
            }

            // 5. Relax edges and update distances
            for (auto& neighbor : adj[source]) {
                int adjNode = neighbor.first;
                int edW = neighbor.second;
                if (dist[adjNode] > time + edW) {
                    dist[adjNode] = time + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // 6. Check for unreachable nodes
        int maxTime = *max_element(dist.begin(), dist.end());
        return maxTime == INT_MAX ? -1 : maxTime; // Return -1 if any node is unreachable
    }
};
