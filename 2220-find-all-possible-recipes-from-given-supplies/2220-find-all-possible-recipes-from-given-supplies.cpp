class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        for(int i=0; i<recipes.size(); i++){
            for(auto ing: ingredients[i]){
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        queue<string> qu;
        for(auto& s:supplies){
            qu.push(s);
        }
        unordered_set<string> made;
        while(! qu.empty()){
            string curr = qu.front();
            qu.pop();
            for(auto& next : graph[curr]){
                if(--indegree[next] == 0){
                    qu.push(next);
                    made.insert(next);
                }
            }
        }
        vector<string> ans;
        for(auto& r : recipes){
            if(made.count(r)){
                ans.push_back(r);
            }
        }
        return ans;
    }
};