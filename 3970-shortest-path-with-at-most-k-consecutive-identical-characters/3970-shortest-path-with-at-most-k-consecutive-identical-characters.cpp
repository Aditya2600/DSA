class Solution {
    struct Node {
        int u;
        int count;
        int wt;

        bool operator>(const Node& other) const{
            return wt > other.wt;
        }
    };
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(const auto& edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }
        vector<vector<int>> dist(n, vector<int>(k+1, 1e9));
        priority_queue<Node, vector<Node>, greater<Node>> minheap;
        dist[0][1] = 0;
        minheap.push({0, 1, 0});

        while(!minheap.empty()){
            auto [u, count, wt] = minheap.top();
            minheap.pop();

            if(u == n-1){
                return wt;
            }
            if(wt > dist[u][count]){
                continue;
            }
            for(const auto &[v, edge_wt] : adj[u]){
                int next_count = (labels[u] == labels[v]) ? count + 1 : 1;
                if(next_count > k){
                    continue;
                }

                if(edge_wt + dist[u][count] < dist[v][next_count]){
                    dist[v][next_count] = edge_wt + dist[u][count];
                    minheap.push({v, next_count, edge_wt + dist[u][count]});
                }
            }
        }
        return -1;
    }
};