//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	const int mod = 1e9 + 7;
    
    int perfectSum(int arr[], int n, int sum) {
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
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends