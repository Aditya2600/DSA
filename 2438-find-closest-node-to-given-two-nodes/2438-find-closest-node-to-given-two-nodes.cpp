class Solution {
public:
    vector<int> bfs(int src, vector<int>& edges){
        int n = edges.size();
        queue<int> q;
        vector<bool> vis(n,false);
        vector<int> dist(n, -1);
        

        int curr = src;
        int d = 0;

        while(curr != -1 && !vis[curr]){
            dist[curr] = d++;
            vis[curr] = true;
            curr = edges[curr];
            
        }
        return dist;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1 = bfs(node1, edges);
        vector<int> dis2 = bfs(node2, edges);
        
        int min_dist = INT_MAX;
        int res = -1;
        for(int i=0; i<n; i++){
            if(dis1[i] != -1 && dis2[i] != -1){
                int max_dist = max(dis1[i], dis2[i]);
                if(max_dist < min_dist || (dis1 == dis2 && i < res)){
                    min_dist = max_dist;
                    res = i;
                }
            }
            
        }
        return res;
    }
};