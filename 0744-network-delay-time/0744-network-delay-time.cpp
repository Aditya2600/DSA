class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it : times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int time = curr.first;
            int source = curr.second;
            if(time > dist[source]) continue;
            for(auto neighbour : adj[source]){
                int adjNode = neighbour.first;
                int edW  = neighbour.second;
                if(dist[adjNode] > edW + time){
                    dist[adjNode] = edW + time;
                    pq.push({edW+time,adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1; i<=n; i++){
            ans = max(ans,dist[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};