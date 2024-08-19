//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
    vector<int> dp1(n, 1);
        
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                if(nums[i] > nums[prev] && 1 + dp1[prev] > dp1[i]){
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }
        int maxi = 0;
        vector<int> dp2(n, 1);
        
        for(int i=n-1; i>=0; i--){
            for(int prev=n-1; prev>i; prev--){
                if(nums[i] > nums[prev] && 1 + dp2[prev] > dp2[i]){
                    dp2[i] = 1 + dp2[prev];
                }
            }
            if(dp1[i] >= 2 && dp2[i] >=2){
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }
        return maxi;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
    }
}

// } Driver Code Ends