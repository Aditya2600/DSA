//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	 const int mod = 1e9 + 7;

    // Recursive function to find the number of subsets with the given sum.
    int f(int arr[], int sum, int ind, vector<vector<int>> &dp) {
        // Base case: When there are no elements left to consider.
        if (ind < 0) {
            return (sum == 0) ? 1 : 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];
        // Not picking the current element.
        int notPick = f(arr, sum, ind - 1, dp);

        // Picking the current element if it's not larger than the remaining sum.
        int pick = 0;
        if (arr[ind] <= sum) {
            pick = f(arr, sum - arr[ind], ind - 1, dp);
        }

        // Return the sum of both possibilities, taking modulo to prevent overflow.
        return dp[ind][sum] = (notPick + pick) % mod;
    }

    int perfectSum(int arr[], int n, int sum) {
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return f(arr, sum, n-1, dp);
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