class Solution {
public:
    // vector<int> bfs(int src, vector<int>& edges){
    //     int n = edges.size();
    //     queue<int> q;
    //     vector<bool> vis(n,false);
    //     vector<int> dist(n, -1);
        

    //     int curr = src;
    //     int d = 0;

    //     while(curr != -1 && !vis[curr]){
    //         dist[curr] = d++;
    //         vis[curr] = true;
    //         curr = edges[curr];
            
    //     }
    //     return dist;
    // }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        queue<pair<int, int>> q;
        vector<vector<int>> dis(n, vector<int> (2, -1));
        dis[node1][0] = 0;
        dis[node2][1] = 0;
        q.push({node1, 0});
        q.push({node2, 1});
        while(!q.empty()){
            auto& [curr, type] = q.front();
            
            if(edges[curr] != -1 && dis[edges[curr]][type] == -1){
                dis[edges[curr]][type] = 1 + dis[curr][type];
                q.push({edges[curr], type});
            }
            q.pop();
        }
        int meeting_distance = INT_MAX;
        int meeting_point = INT_MAX;
        for(int i=0; i<n; i++){
            if(dis[i][0] != -1 && dis[i][1] != -1){
                int curr_distance = max(dis[i][0],dis[i][1]);
                if(curr_distance < meeting_distance){
                    meeting_distance = curr_distance;
                    meeting_point = i;
                }
            }           
        }
        return meeting_point == INT_MAX ? -1 : meeting_point;
        // int n = edges.size();       
        // vector<int> dis1 = bfs(node1, edges);
        // vector<int> dis2 = bfs(node2, edges);
        
        // int min_dist = INT_MAX;
        // int res = -1;
        // for(int i=0; i<n; i++){
        //     if(dis1[i] != -1 && dis2[i] != -1){
        //         int max_dist = max(dis1[i], dis2[i]);
        //         if(max_dist < min_dist || (dis1 == dis2 && i < res)){
        //             min_dist = max_dist;
        //             res = i;
        //         }
        //     }
            
        // }
        // return res;
    }
};