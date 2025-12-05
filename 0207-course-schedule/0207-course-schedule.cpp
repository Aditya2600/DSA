class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto it : prerequisites){
            int u = it[1];
            int v = it[0];
            adj[u].push_back(v);
        }
        int cnt = 0;
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
            cnt++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    qu.push(it);
                }
            }
        }
        return cnt == numCourses;
    }
};