//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int dp[501][501];
    int unsub(string &s, string &t, int i, int j){
        if(i >= s.size()) return 501;
        if(j >= t.size()) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int k = j;
        for(;k<t.size(); k++){
            if(s[i] == t[k]) break;
        }
        if(k == t.size()) return 1;
        return dp[i][j] = min(unsub(s,t,i+1,j), 1+unsub(s,t,i+1,k+1));
    }
    int shortestUnSub(string S, string T) {
        memset(dp, -1, sizeof dp);
        int ans = unsub(S,T,0,0);
        if(ans >= 501) return -1;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends