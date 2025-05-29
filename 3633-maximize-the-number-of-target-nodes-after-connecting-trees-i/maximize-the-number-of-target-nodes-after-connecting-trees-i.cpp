class Solution {
public:
    
    int bfs(int node, int k, vector<vector<int>> &adj, int size){
        vector<int> vis(size, 0);
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        int cnt = 0;
        int dist = 0;
        while(!q.empty() && dist <= k){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                cnt++;
                for(auto neigh : adj[curr]){
                    if(!vis[neigh]){
                        vis[neigh] = 1;
                        q.push(neigh);
                    }
                }
            }
            dist++;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>> adj1(n+1);
        for(auto it : edges1){
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        vector<vector<int>> adj2(m+1);
        for(auto it : edges2){
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        
        vector<int> cnt1(n+1);
        for(int i=0; i<=n; i++){
            cnt1[i] = bfs(i, k, adj1, n+1);
        }
        int goldenNode = 0;
        for(int i=0; i<=m; i++){
            int cnt = bfs(i, k-1, adj2, m+1);
            if(cnt > goldenNode){
                goldenNode = cnt;
            }
        }
        vector<int> ans(n+1);
        for(int i=0; i<=n; i++){
            int totalTarget = cnt1[i] + goldenNode;
            ans[i] += totalTarget;
        }
        return ans;
    }
};