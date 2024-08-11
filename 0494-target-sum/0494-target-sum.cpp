class Solution {
public:
    int perfectSum(vector<int>& arr, int n, int sum) {
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int ind = 1; ind <= n; ind++) {
            for (int targetSum = 0; targetSum <= sum; targetSum++) {
                int notPick = dp[ind - 1][targetSum];
                int pick = 0;
                if (arr[ind - 1] <= targetSum) {
                    pick = dp[ind - 1][targetSum - arr[ind - 1]];
                }
                dp[ind][targetSum] = (notPick + pick); 
            }
        }
        return dp[n][sum];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        int totalSum = 0;
        for(int i=0; i<n; i++) totalSum += arr[i];
        if(totalSum - d < 0 || (totalSum - d)%2) return false;
        return perfectSum(arr, n, (totalSum - d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n, target, nums);
    }
};