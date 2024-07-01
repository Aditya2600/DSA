class Solution {
public:
    struct Edge{
        int src;
        int destn;
        int wt;
    };
    int find(vector<int> &parent, int a){
        return parent[a] = (parent[a] == a)? a : find(parent,parent[a]);
    }
    static bool cmp(const Edge &e1,const Edge &e2){
        return e1.wt < e2.wt;
    }
    void Union(vector<int> &parent, vector<int> &rank, int a, int b){
        a = find(parent,a);
        b = find(parent,b);
        if(a == b) return;
        if(rank[a] >= rank[b]){
            parent[b] = a;
            rank[a]++;
        }
        else{
            parent[a] = b;
            rank[b]++;
        }
    }
    long long int kruskals(vector<Edge> &input,int n){
        sort(input.begin(),input.end(),cmp);
        vector<int> parent(n);
        vector<int> rank(n,1);
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int ans = 0;
        int edgeCount = 0;
        int i = 0;
        while(edgeCount < n-1 && i < input.size()){
            Edge curr = input[i];
            int srcPar = find(parent,curr.src);
            int destnPar = find(parent,curr.destn);
            if(srcPar != destnPar){
                Union(parent,rank,srcPar,destnPar);
                edgeCount++;
                ans+=curr.wt;
            }
            i++;
        }
        return ans;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j) continue;
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({i,j,w});
            }
        }
        return kruskals(edges,n);
    }
};