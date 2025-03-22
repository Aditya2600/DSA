class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        unordered_set<string> available(supplies.begin(), supplies.end());

        // Step 1: Build the graph and indegree map
        for (int i = 0; i < recipes.size(); i++) {
            for (const string& ingredient : ingredients[i]) {
                graph[ingredient].push_back(recipes[i]);
                indegree[recipes[i]]++; // Recipe depends on this ingredient
            }
        }

        // Step 2: Initialize queue with all available supplies
        queue<string> q;
        for (const string& supply : supplies) {
            q.push(supply);
        }

        vector<string> result;

        // Step 3: Process recipes in topological order
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            // If this item is a recipe, we can add it to the result
            if (indegree.count(item)) result.push_back(item);

            // Reduce the indegree of dependent recipes
            for (const string& next : graph[item]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return result;
    }
};