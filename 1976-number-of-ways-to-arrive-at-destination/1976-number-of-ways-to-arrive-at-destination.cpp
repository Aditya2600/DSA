class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long inf = 1e18;
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto e : roads) {
            int u = e[0];
            int v = e[1];
            int time = e[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        pq.push({0, 0});
        vector<long long> dist(n, inf);
        vector<long long> ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        while (!pq.empty()) {
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            for (auto it : adj[node]) {
                int newNode = it.first;
                int newDis = it.second;
                if (dist[newNode] > dis + newDis) {
                    dist[newNode] = dis + newDis;
                    ways[newNode] = ways[node];
                    pq.push({dist[newNode], newNode});
                } else if (dist[newNode] == dis + newDis) {
                    ways[newNode] = (ways[node] + ways[newNode]) % MOD;
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};