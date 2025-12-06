class Solution {
public:
    typedef pair<int, int> p;
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if(n == 1 || n == 0) return 0;
        queue<p> q;
        set<p> visited;
        for(int i=0; i<n; i++){
            int mask = 1 << i;
            q.push({i, mask});
            visited.insert({i, mask});
        }
        int path = 0;
        int allVisited = (1 << n) - 1;

        while(!q.empty()){
            int sz = q.size();
            path++;
            while(sz--){
                p node = q.front();
                q.pop();
                int currNode = node.first;
                int currMask = node.second;
                for(auto &adj : graph[currNode]){
                    int nextMask = currMask | 1 << adj;
                    if(nextMask == allVisited){
                        return path;
                    }
                    if(visited.find({adj, nextMask}) == visited.end()){
                        visited.insert({adj, nextMask});
                        q.push({adj, nextMask});
                    }
                }
            }
        }
        return -1;
    }
};