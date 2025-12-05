class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        for(auto &edge : prerequisites){
            adj[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> qu;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                qu.push(i);
            }
        }
        unordered_map<int, unordered_set<int>> mp;
        while(!qu.empty()){
            int node = qu.front();
            qu.pop();

            for(auto &ngbh : adj[node]){
                mp[ngbh].insert(node);
                for(auto &preq : mp[node]){
                    mp[ngbh].insert(preq);
                }
                indegree[ngbh]--;
                if(indegree[ngbh] == 0){
                    qu.push(ngbh);
                }
            }
        }
        vector<bool> res;
        for(int i=0; i<queries.size(); i++){
            int u = queries[i][0];
            int v = queries[i][1];
            res.push_back(mp[v].count(u) > 0);
        }
        return res;
    }
};