// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int
//     dst, int k) {
//         unordered_map<int, vector<pair<int, int>>> adj;
//         for(auto it : flights){
//             int u = it[0];
//             int v = it[1];
//             int w = it[2];
//             adj[u].push_back({v, w});
//         }

//         vector<int> dist(n, 1e9);
//         priority_queue<pair<int, int>, vector<pair<int, int>>,
//         greater<pair<int, int>>> pq; pq.push({0, 0}); dist[0] = 0;
//         while(!pq.empty()){
//             int p = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
//             k--;
//             if(k == 0 && node == dst){
//                 return p;
//             }
//             for(auto it : adj[node]){
//                 int price = it.second;
//                 int newNode = it.first;
//                 if(p + price < dist[newNode]){
//                     dist[newNode] = p + price;
//                     pq.push({p + price, newNode});
//                 }
//             }
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        vector<int> dist(n, 1e9);
        queue<pair<int, int>> q;
        q.push({0, src});
        dist[src] = 0;
        int steps = 0;
        while (!q.empty() && steps <= k) {
            int N = q.size();
            while (N--) {
                int p = q.front().first;
                int node = q.front().second;
                q.pop();
                for (auto it : adj[node]) {
                    int price = it.second;
                    int newNode = it.first;
                    
                    if (p + price < dist[newNode]) {
                        dist[newNode] = p + price;
                        q.push({p + price, newNode});
                    }
                }
            }
            steps++;
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};