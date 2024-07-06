#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

vector<unordered_map<int,int>> graph;
int v;
void add_edge(int src, int dest, int wt, bool bi_dir = true){
    graph[src][dest] = wt;
    if(bi_dir){
        graph[dest][src] = wt;
    }
}
bool bfs(int src){
    unordered_set<int> vis;
    queue<int> qu;
    vector<int> par(v,-1);
    qu.push(src);
    vis.insert(src);
    while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbour : graph[src]){
            if(vis.count(neighbour) and par[curr] != neighbour) return true;
            if(!vis.count(neighbour)){
                vis.insert(neighbour);
                par[neighbour] = curr;
                qu.push(neighbour);

            }
        }
    }
}
    bool has_cycle(){
        unordered_set<int> vis;
        for(int i=0; i<v; i++){
            if(!vis.count(i)){
                bool result = dfs(i);
                if(result == true) return true;
            }
        }
        return false; 
    }
