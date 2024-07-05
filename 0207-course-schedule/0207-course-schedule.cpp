class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> graph(numCourses);
        for(auto it:prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto neighbour : graph[i]){
                indegree[neighbour]++;
            }
        }
        queue<int> qu;
        unordered_set<int> vis;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0){
                qu.push(i);
                vis.insert(i);
            }
        }
        int count = 0;
        while(not qu.empty()){
            int node = qu.front();
            qu.pop();
            count++;
            for(auto neighbour : graph[node]){
                if(not vis.count(neighbour)){
                    indegree[neighbour]--;
                    if(indegree[neighbour] == 0){
                        qu.push(neighbour);
                        vis.insert(neighbour);
                    }
                }
            }
        }
        if(count == numCourses) return true;
        return false;
    }
};