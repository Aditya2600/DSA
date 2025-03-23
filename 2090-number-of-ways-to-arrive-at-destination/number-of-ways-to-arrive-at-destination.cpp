class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq; // Changed to long long for distances
        vector<long long> dist(n,1e15), ways(n,0);
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        long long mod = (int)(1e9 + 7);
        
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (dis > dist[node]) continue;
            for(auto neighbour : adj[node]){
                int adjNode = neighbour.first;
                long long wt = neighbour.second;
                if(dist[adjNode] > dis + wt){
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if(dist[adjNode] == dis + wt){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};
