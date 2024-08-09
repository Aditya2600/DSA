//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here.   
	    int sum = 0 ;
        for(int i=0; i<n; i++) sum += nums[i]; 
        vector<vector<bool>> dp(n, vector<bool> (sum+1, 0));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(nums[0] <= sum) dp[0][nums[0]] = true;
        for(int ind=1; ind<n; ind++){
            for(int k=1; k<=sum; k++){
                bool notTake = dp[ind-1][k];
                bool take = false;
                if(nums[ind] <= k) take = dp[ind-1][k-nums[ind]];
                dp[ind][k] = take | notTake;
            }
        }
        int mini = 1e9;
        for(int s1 = 0; s1<=sum/2; s1++){
            if(dp[n-1][s1] == true){
                mini = min(mini, abs((sum - s1) - s1));
            }
        }
        return mini;
    }
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends