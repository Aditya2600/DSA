//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
    // Step 1: Calculate indegree for all vertices
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto neighbour : adj[i]) {
            indegree[neighbour]++;
        }
    }

    // Step 2: Push all vertices with indegree 0 into the queue
    queue<int> qu;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            qu.push(i);
        }
    }

    // Step 3: Process the graph and perform topological sort
    int processedCount = 0; // To count how many nodes are processed
    while (!qu.empty()) {
        int node = qu.front(); // Corrected from qu.top() to qu.front()
        qu.pop();
        processedCount++;

        // Reduce the indegree of neighbors
        for (auto neighbour : adj[node]) {
            indegree[neighbour]--;
            // If indegree becomes 0, add the neighbor to the queue
            if (indegree[neighbour] == 0) {
                qu.push(neighbour);
            }
        }
    }

    // Step 4: If we processed all nodes, there's no cycle. Otherwise, there is a cycle.
    return (processedCount != V); // If processedCount != V, there's a cycle
}

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends