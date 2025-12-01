class Solution {
    private:
        bool dfs(int node, vector<vector<int>>& graph, vector<int>& check, vector<int>& vis, vector<int>& pathVis){
            vis[node] = 1;
            pathVis[node] = 1;
            check[node] = 0;

            for(auto it : graph[node]){
                if(!vis[it]){
                    if(dfs(it, graph, check, vis, pathVis)){
                        check[it] = 0;
                        return true;
                    }
                }
                else if(pathVis[it]){
                    check[it] = 0;
                    return true;
                }
            }
            pathVis[node] = 0;
            check[node] = 1;
            return false;
        }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> safeNode;
        vector<int> check(v, 0);
        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);
        for(int i=0; i<v; i++){
            if(!vis[i]){
                dfs(i, graph, check, vis, pathVis);
            }
        }
        for(int i=0; i<v; i++){
            if(check[i] == 1) safeNode.push_back(i);
        }
        return safeNode;
    }
};