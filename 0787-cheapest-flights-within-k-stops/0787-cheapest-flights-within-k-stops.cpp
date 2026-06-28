class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto edg : flights) {
            int u = edg[0];
            int v = edg[1];
            int wt = edg[2];
            adj[u].push_back({v, wt});
        }

        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        dist[src][0] = 0;
        pq.push({0, {src, 0}}); // {cost, {node, flights_taken}};
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int wt = top.first;
            int u = top.second.first;
            int stop = top.second.second;

            if (u == dst) {
                return wt;
            }

            if (stop == k + 1) {
                continue;
            }

            if(wt > dist[u][stop]){
                continue;
            }

                for (auto x : adj[u]) {
                    int v = x.first;
                    int nextWt = x.second;
                    int newStop = stop + 1;

                    if (dist[u][stop] + nextWt < dist[v][newStop]) {
                        dist[v][newStop] = dist[u][stop] + nextWt;
                        pq.push({dist[u][stop] + nextWt, {v, newStop}});
                    }
                }
        }
        return -1;
    }
};