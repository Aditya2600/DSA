//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    // Function to perform BFS and record the shape of the island
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& ans) {
        visited[i][j] = true;
        int n = grid.size();
        int m = grid[0].size();
        
        // Directions: right, down, left, up (4 directions)
        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({i, j});
        
        // Record the base point (i, j) and then all other points relative to it
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            int r = temp.first;
            int c = temp.second;
            
            // Record the relative position (current cell - starting cell)
            ans.push_back({r - i, c - j});
            
            // Explore 4 possible directions (right, down, left, up)
            for (int d = 0; d < direction.size(); d++) {
                int nr = r + direction[d][0];  // new row
                int nc = c + direction[d][1];  // new column
                
                // If it's a valid cell, not visited, and is land, continue BFS
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Set to store unique island shapes
        set<vector<pair<int, int>>> distinctIslands;
        
        // Visited array to track whether a cell has been explored
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        // Iterate through the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If it's an unvisited land cell, start a BFS
                if (grid[i][j] == 1 && !visited[i][j]) {
                    vector<pair<int, int>> shape;  // To store the shape of the current island
                    bfs(i, j, grid, visited, shape);
                    
                    // Insert the shape into the set (set ensures uniqueness)
                    distinctIslands.insert(shape);
                }
            }
        }
        
        // The number of distinct islands is the size of the set
        return distinctIslands.size();
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends