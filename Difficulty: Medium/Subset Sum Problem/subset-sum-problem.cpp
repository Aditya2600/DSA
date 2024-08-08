//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        for(int i=0; i<n; i++) dp[i][0] = true;
        if(arr[0] <= sum)dp[0][arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int k=1; k<=sum; k++){
                bool notTake = dp[i-1][k];
                bool take = false;
                if(arr[i] <= k) take = dp[i-1][k-arr[i]];
                dp[i][k] = take | notTake;
            }
        }
        return dp[n-1][sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends