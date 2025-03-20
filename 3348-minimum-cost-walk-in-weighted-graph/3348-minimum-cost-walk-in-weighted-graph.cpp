class Solution {
public:
        
    void dfs(int node, vector<vector<int>>& gr, vector<int> &vis, int compNum, unordered_map<int, int> &nodeToComp){
        vis[node] = 1;
        nodeToComp[node] = compNum;
        for(auto ne : gr[node]){
            if(!vis[ne]){
                dfs(ne, gr, vis, compNum, nodeToComp);
            }
        }
    }


    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int z = edges.size();
        vector<vector<int>> gr(n, vector<int> (0));
        for(int i=0; i<z; i++){
            int u = edges[i][0], v = edges[i][1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        unordered_map<int, int> nodeToComp;
        int compNum = 1;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, gr, vis, compNum, nodeToComp);
                compNum++;
            }
        }
        vector<int> compAndScore(n, pow(2, 31)-1);
        for(int i=0; i<z; i++){
            int u = edges[i][0], v = edges[i][1];
            int uComp = nodeToComp[u];
            compAndScore[uComp] = compAndScore[uComp] & edges[i][2]; 
        }

        vector<int> ans;
        int op = query.size();
        for(int i=0; i<op; i++){
            if(query[i][0] == query[i][1]){
                ans.push_back(0);
            }
            else if(nodeToComp[query[i][0]] == nodeToComp[query[i][1]]){
                ans.push_back(compAndScore[nodeToComp[query[i][0]]]);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};