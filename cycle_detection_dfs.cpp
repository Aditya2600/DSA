#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<unordered_map<int,int>> graph;
int v;
void add_edge(int src, int dest, int wt, bool bi_dir = true){
    graph[src][dest] = wt;
    if(bi_dir){
        graph[dest][src] = wt;
    }
}
bool dfs(int src, int parent, unordered_set<int> &vis){
    vis.insert(src);
    for(auto neighbour : graph[src]){
        if(vis.count(neighbour) and neighbour != parent){
            return true;
        }
        if(!vis.count(neighbour)){
            dfs(neighbour,src,vis);
        }
    }
    return false;
}
    bool has_cycle(){
        unordered_set<int> vis;
        bool result = false;
        for(int i=0; i<v; i++){
            if(!vis.count(i)){
                result = dfs(i,-1,vis);
                if(res == true) return true;
            }
        }
        return false; 
    }


