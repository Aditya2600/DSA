// class Solution {
// public:
//     int n;
//     vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//     int dfs(vector<vector<int>>& grid, int i, int j,
//             vector<vector<bool>>& vis) {
//         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 ||
//         vis[i][j]) {
//             return 0;
//         }
//         vis[i][j] = true;
//         int size = 1;
//         for (vector<int>& dir : directions) {
//             int i_ = i + dir[0];
//             int j_ = j + dir[1];

//             size += dfs(grid, i_, j_, vis);
//         }
//         return size;
//     }

//     int largestIsland(vector<vector<int>>& grid) {
//         n = grid.size();
//         int maxArea = 0;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     grid[i][j] = 1;

//                     int largestIslandSize = 0;
//                     vector<vector<bool>> vis(n, vector<bool>(n, false));
//                     for (int x = 0; x < n; x++) {
//                         for (int y = 0; y < n; y++) {
//                             if (grid[x][y] == 1 && !vis[x][y]) {
//                                 largestIslandSize = max(largestIslandSize,
//                                                         dfs(grid, x, y,
//                                                         vis));
//                             }
//                         }
//                     }
//                     maxArea = max(maxArea, largestIslandSize);
//                     grid[i][j] = 0;
//                 }
//             }
//         }
//         if(maxArea == 0) return n*n;
//         return maxArea;
//     }
// };

// class Solution {
// public:
//     int n;
//     vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//     int dfs(vector<vector<int>>& grid, int i, int j,
//             vector<vector<bool>>& vis) {
//         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 ||
//         vis[i][j]) {
//             return 0;
//         }
//         vis[i][j] = true;
//         int size = 1;
//         for (vector<int>& dir : directions) {
//             int i_ = i + dir[0];
//             int j_ = j + dir[1];

//             size += dfs(grid, i_, j_, vis);
//         }
//         return size;
//     }

//     int largestIsland(vector<vector<int>>& grid) {
//         n = grid.size();
//         int maxArea = 0;
//         vector<vector<bool>> vis(n, vector<bool>(n, false));

//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(!vis[i][j] && grid[i][j] == 1){
//                     maxArea = max(maxArea, dfs(grid, i, j, vis));
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     grid[i][j] = 1;

//                     vis =  vector<vector<bool>> (n, vector<bool>(n, false));
//                     int size = dfs(grid, i, j, vis);

//                     maxArea = max(maxArea, size);
//                     grid[i][j] = 0;
//                 }
//             }
//         }
//         if(maxArea == 0) return n*n;
//         return maxArea;
//     }
// };

// class Solution {
// public:
//     int n;
//     vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

//     int dfs(vector<vector<int>>& grid, int i, int j,
//             vector<vector<bool>>& vis) {
//         if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 ||
//         vis[i][j]) {
//             return 0;
//         }
//         vis[i][j] = true;
//         int size = 1;
//         for (vector<int>& dir : directions) {
//             int i_ = i + dir[0];
//             int j_ = j + dir[1];

//             size += dfs(grid, i_, j_, vis);
//         }
//         return size;
//     }

//     int largestIsland(vector<vector<int>>& grid) {
//         n = grid.size();
//         int maxArea = 0;
//         vector<vector<bool>> vis(n, vector<bool>(n, false));

//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(!vis[i][j] && grid[i][j] == 1){
//                     maxArea = max(maxArea, dfs(grid, i, j, vis));
//                 }
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 0) {
//                     grid[i][j] = 1;

//                     vis =  vector<vector<bool>> (n, vector<bool>(n, false));
//                     int size = dfs(grid, i, j, vis);

//                     maxArea = max(maxArea, size);
//                     grid[i][j] = 0;
//                 }
//             }
//         }
//         if(maxArea == 0) return n*n;
//         return maxArea;
//     }
// };

class Solution {
public:
    int n;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis,
            int id) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 ||
            vis[i][j]) {
            return 0;
        }
        grid[i][j] = id;
        vis[i][j] = true;
        int size = 1;
        for (vector<int>& dir : directions) {
            int i_ = i + dir[0];
            int j_ = j + dir[1];

            size += dfs(grid, i_, j_, vis, id);
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        int maxArea = 0;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        int id = 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int size = dfs(grid, i, j, vis, id);
                    maxArea = max(maxArea, size);
                    mp[id] = size;
                    id++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIds;
                    for (auto& dir : directions) {
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if (i_ >= 0 && i_ < n && j_ >= 0 && j_ < n &&
                            grid[i_][j_] != 0) {
                            uniqueIds.insert(grid[i_][j_]);
                        }
                    }
                    int overAllSize = 1;
                    for (auto& id : uniqueIds) {
                        overAllSize += mp[id];
                    }

                    maxArea = max(maxArea, overAllSize);
                }
            }
        }
        return maxArea;
    }
};