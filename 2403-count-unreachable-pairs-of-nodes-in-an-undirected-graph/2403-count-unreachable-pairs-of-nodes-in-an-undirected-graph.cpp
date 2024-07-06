class Solution {
public:
    int dfs(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node]=1;
        int ans = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
            ans += dfs(it,vis,adj);
            }
        }
        return ans;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> counts;
        vector<int> vis(n,false);

        for(int i=0; i<n; i++){
            if(!vis[i]){
                int connected = dfs(i,vis,adj);
                counts.push_back(connected);  

            }
        }
        long long ans = 0;
        long long t = 0;
        for(int i=0; i<counts.size(); i++){
            t+=counts[i];
            ans += (n-t)*counts[i];
        }
        return ans;
    }
};