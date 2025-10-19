// class Solution {
// public:
//     bool isSafe(int v, vector<int>& colors, int col, vector<vector<int>>&
//     adj) {
//         for (auto e : adj[v]) {
//             if (colors[e] == col) {
//                 return false;
//             }
//         }
//         return true;
//     }
//     bool dfs(int v, vector<vector<int>>& adj, vector<int>& colors) {
//         if (v == adj.size()) {
//             return true;
//         }
//         for (int c = 1; c <= 4; c++) {
//             if (isSafe(v, colors, c, adj)) {
//                 colors[v] = c;
//                 if(dfs(v + 1, adj, colors)) return true;
//                 colors[v] = 0;
//             }
//         }
//         return false;
//     }
//     vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
//         vector<vector<int>> adj(n);
//         for (auto e : paths) {
//             adj[e[0] - 1].push_back(e[1] - 1);
//             adj[e[1] - 1].push_back(e[0] - 1);
//         }
//         vector<int> colors(n, 0);
//         dfs(0, adj, colors);
//         return colors;
//     }
// };

class Solution {
public:
    bool isSafe(int v, vector<int>& colors, int col, vector<vector<int>>& adj) {
        for (auto e : adj[v]) {
            if (colors[e] == col) {
                return false;
            }
        }
        return true;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for (auto e : paths) {
            adj[e[0] - 1].push_back(e[1] - 1);
            adj[e[1] - 1].push_back(e[0] - 1);
        }
        vector<int> colors(n, 0);
        for (int v = 0; v < n; v++) {
            for (int c = 1; c <= 4; c++) {
                if (isSafe(v, colors, c, adj)) {
                    colors[v] = c;
                }
            }
        }
        return colors;
    }
};