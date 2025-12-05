class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        vector<int> topo;
        queue<int> qu;
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();
            topo.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    qu.push(it);
                }
            }
        }
        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};
