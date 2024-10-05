class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> adjRev[v];
        vector<int> indegree(v, 0);
        for(int i = 0; i < v; i++){
            for(auto it : graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> qu;
        vector<int> safeNode;
        for(int i = 0; i < v; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            safeNode.push_back(node);
            for(auto neighbors : adjRev[node]){
                indegree[neighbors]--;
                if(indegree[neighbors] == 0){
                    qu.push(neighbors);
                }
            }
        }
        sort(safeNode.begin(), safeNode.end());
        return safeNode;
    }
};