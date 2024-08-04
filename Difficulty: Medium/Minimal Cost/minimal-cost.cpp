//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
//   int minimizeCostHelper(vector<int>& arr, int& k, int ind, vector<int> &dp){
//       int n = arr.size();
//       if(ind == 0) return 0;
//       if(dp[ind] != -1) return dp[ind];
//       int ans = INT_MAX;
//       for(int i=1; i<=k; i++){
//           if(ind-i >= 0){
//       int jump = minimizeCostHelper(arr, k, ind-i, dp) + abs(arr[ind] - arr[ind-i]);
//       ans = min(ans, jump);
//       }
//      }
//      return dp[ind] = ans;
//   }
    int minimizeCost(vector<int>& arr, int& k) {
         int n = arr.size();
    //     vector<int> dp(n+1,-1);
    //   return minimizeCostHelper(arr,k,n-1,dp);
        int dp[n];
        dp[0] = 0;
        for(int ind=1; ind<n; ind++){
            int ans = INT_MAX;
            for(int i=1; i<=k; i++){
            if(ind-i >= 0){
                int jump = dp[ind-i] + abs(arr[ind] - arr[ind-i]);
                ans = min(ans, jump);
            }
            
        }
          dp[ind] = ans;
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends