//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class LRUCache{
    list<int> dq;
    unordered_map<int, list<int>::iterator> ma;
    int csize;
public:
        LRUCache(int);
        void refer(int);
        bool contains(int);
};

LRUCache :: LRUCache(int n){
    csize = n;
}
void LRUCache :: refer(int x){
    if(ma.find(x) == ma.end()){
        if(dq.size() == csize){
            int last = dq.back();
            dq.pop_back();
            ma.erase(last);
        }
    }
    else dq.erase(ma[x]);
    dq.push_front(x);
    ma[x] = dq.begin();
}
    bool LRUCache :: contains(int x){
        return ma.find(x) != ma.end();
    }
    
class Solution{
public:

    int pageFaults(int N, int C, int pages[]){
        // code here
        LRUCache cache(C);
        int pageFaults = 0;
        for(int i=0; i<N; i++){
            int page = pages[i];
            if(!cache.contains(page)){
                pageFaults++;
            }
            cache.refer(page);
        }
        return pageFaults;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends