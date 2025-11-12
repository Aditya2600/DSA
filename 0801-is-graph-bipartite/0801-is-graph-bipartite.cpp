class Solution {
public:
    bool checkBipartiteDfs(int node, vector<int>& color, vector<vector<int>>& graph, int currColor){
        color[node] = currColor;
        for(auto &v : graph[node]){
            if(color[v] == -1){
                color[v] = 1 - currColor;
                if(checkBipartiteDfs(v, color, graph, color[v]) == false){
                    return false;
                }
            }
            else if(color[v] == currColor){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(checkBipartiteDfs(i, color, graph, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};