#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<unordered_set>
using namespace std;

#define pp as pair<int,int>;

vector<list<pp> > gr;
void add_edge(int u, int v, int wt, bool bidir = true){
    gr[u].push_back[{v,wt}];
    if(bidir){
        gr[v].push_back[{u,wt}];
    }
}
unordered_map<int,int> djisktra(int src, int n){
    priority_queue<pp,vector<pp> > pq;
    vector<int> via(n+1);
    unordered_set<int> vis;
    unordered_map<int,int> mp;
    for(int i=0; i<=n; i++){
        mp[i] = INT_MAX;
    }
    pq.push(0,src);
    mp[src] = 0;
    while(!pq.empty()){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
    
    for(auto neighbour : gr[curr.second]){
        if(!vis.count(neighbour.first) && mp[neighbour.first] > mp[curr.second] + neighbour.second){
            pq.push({mp[curr.second] + neighbour.second, neighbour.first});
            via[neighbour.first] = curr.second;
            mp[neighbour.first] = mp[curr.second] + neighbour.second;
        }
    }
}
return mp;
}
int main(){
    int n,m;
    cin>>n>>m;
    gr.resize(n+1, list<pp> ());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int, int> sp = djisktra(src,n);
    int dest;
    cin>>dest;
    cout<<sp[dest]<<"\n";
    return 0;
}