//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  vector<int> topoSort(int V, vector<int> adj[]) {
    // Step 1: Calculate indegree for all vertices
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++) {
        for (auto neighbour : adj[i]) {
            indegree[neighbour]++;
        }
    }

    // Step 2: Push all vertices with indegree 0 into the queue
    queue<int> qu;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            qu.push(i);
        }
    }

    // Step 3: Process the graph and perform topological sort
    vector<int> topo; // To count how many nodes are processed
    while (!qu.empty()) {
        int node = qu.front(); // Corrected from qu.top() to qu.front()
        qu.pop();
        topo.push_back(node);

        // Reduce the indegree of neighbors
        for (auto neighbour : adj[node]) {
            indegree[neighbour]--;
            // If indegree becomes 0, add the neighbor to the queue
            if (indegree[neighbour] == 0) {
                qu.push(neighbour);
            }
        }
    }

    // Step 4: If we processed all nodes, there's no cycle. Otherwise, there is a cycle.
    return topo; // If processedCount != V, there's a cycle
}
  public:
    string findOrder(string dict[], int n, int k) {
       vector<int> adj[k];
       for(int i=0; i<n-1; i++){
           string s1 = dict[i];
           string s2 = dict[i+1];
           int len = min(s1.size(), s2.size());
           for(int ptr = 0; ptr < len; ptr++){
               if(s1[ptr] != s2[ptr]){
                   adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                   break;
               }
           }
       }
       vector<int> topo = topoSort(k, adj);
       string ans = "";
       for(auto it : topo){
           ans = ans + char(it + 'a');
       }
       return ans;
    }
};

//{ Driver Code Starts.
string order;

bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size())
        return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++)
            cin >> dict[i];

        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++)
            order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i])
                f = false;

        if (f)
            cout << 1;
        else
            cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends