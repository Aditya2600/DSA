//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  	const int mod = 1e9 + 7;
    
    int perfectSum(vector<int>& arr, int n, int sum) {
        // Initialize DP table
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        
        // Base case: sum = 0 can always be achieved by empty subset
        for(int i = 0; i <= n; i++) dp[i][0] = 1;

        // Fill the DP table
        for (int ind = 1; ind <= n; ind++) {
            for (int targetSum = 0; targetSum <= sum; targetSum++) {
                int notPick = dp[ind - 1][targetSum];  // Not picking the current element
                int pick = 0;
                if (arr[ind - 1] <= targetSum) {
                    pick = dp[ind - 1][targetSum - arr[ind - 1]];  // Picking the current element
                }
                dp[ind][targetSum] = (notPick + pick) % mod;  // Modulo operation
            }
        }
        
        // The result is stored in dp[n][sum]
        return dp[n][sum];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += arr[i];
        if(totalSum - d < 0 || (totalSum - d)%2) return false;
        return perfectSum(arr, n, (totalSum - d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends