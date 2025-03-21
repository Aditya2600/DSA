#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph; // ingredient → recipes that need it
        unordered_map<string, int> inDegree; // Count of required ingredients
        unordered_set<string> available(supplies.begin(), supplies.end()); // Convert supplies to a set
        queue<string> q; // Queue for topological sorting

        // Initialize in-degree and graph
        for (int i = 0; i < recipes.size(); i++) {
            string recipe = recipes[i];
            inDegree[recipe] = ingredients[i].size(); // Number of ingredients needed
            for (const string& ing : ingredients[i]) {
                graph[ing].push_back(recipe); // "ing" is needed for "recipe"
            }
        }

        // Add initial supplies (ingredients that have no dependency)
        for (const string& supply : supplies) {
            q.push(supply);
        }

        vector<string> result;

        // Topological Sorting (Kahn’s Algorithm)
        while (!q.empty()) {
            string item = q.front();
            q.pop();

            // If item is a recipe, add it to the result
            if (inDegree.count(item)) {
                result.push_back(item);
            }

            // Process all recipes that depend on this ingredient
            for (const string& recipe : graph[item]) {
                inDegree[recipe]--; // Reduce the count of needed ingredients
                if (inDegree[recipe] == 0) { // If all ingredients are available
                    q.push(recipe);
                }
            }
        }

        return result;
    }
};