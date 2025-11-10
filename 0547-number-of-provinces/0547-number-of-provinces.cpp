// class Solution {
// public:
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n = isConnected.size();
//         vector<vector<int>> adj(n);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (isConnected[i][j] == 1 && i != j) {
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
//         vector<int> vis(n, 0);
//         int cnt = 0;
//         for (int i = 0; i < n; i++) {
//             if (!vis[i]) {
//                 cnt++;
//                 vis[i] = 1;
//                 queue<int> q;
//                 q.push(i);

//                 while (!q.empty()) {
//                     int node = q.front();
//                     q.pop();
//                     for (auto it : adj[node]) {
//                         if (!vis[it]) {
//                             q.push(it);
//                             vis[it] = 1;
//                         }
//                     }
//                 }
//             }
//         }
//     return cnt;
//     }
// };

class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] == 1 && vis[j] == 0) {
                vis[j] = 1;
                dfs(j, vis, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int province = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                province++;
                vis[i] = 1;
                dfs(i, vis, isConnected);
            }
        }
        return province;
    }
};
