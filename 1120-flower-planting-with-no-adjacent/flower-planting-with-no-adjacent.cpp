class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        // Create an adjacency list of size n, where each element is a list of
        // neighboring gardens
        vector<vector<int>> graph(n);

        // Populate the adjacency list from the given paths
        // Each path connects two gardens bidirectionally
        for (const auto& path : paths) {
            int a = path[0] - 1;   // Convert to 0-indexed
            int b = path[1] - 1;   // Convert to 0-indexed
            graph[a].push_back(b); // Add b as a neighbor of a
            graph[b].push_back(a); // Add a as a neighbor of b
        }

        // Initialize the answer vector with n zeros, to store the flower type
        // for each garden
        vector<int> answer(n, 0);

        // Iterate through each garden from 0 to n-1
        for (int garden = 0; garden < n; garden++) {
            // Create an array to mark flower types used by adjacent gardens
            // There are 5 entries (index 1 to 4 will be used for clarity; index
            // 0 is ignored)
            vector<bool> used(5, false);

            // Check all adjacent gardens of the current garden
            for (int neighbor : graph[garden]) {
                // If the neighbor has already been assigned a flower type, mark
                // that type as used
                if (answer[neighbor] != 0) {
                    used[answer[neighbor]] = true;
                }
            }

            // Now select the smallest flower type (from 1 to 4) that is not
            // used
            for (int flower = 1; flower <= 4; flower++) {
                if (!used[flower]) { // If this flower type is not used by any
                                     // neighbor
                    answer[garden] =
                        flower; // Assign the flower type to the current garden
                    break; // No need to check further, break out of the loop
                }
            }
        }

        // Return the vector with the resulting flower assignments
        return answer;
    }
};
