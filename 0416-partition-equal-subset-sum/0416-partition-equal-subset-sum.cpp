class Solution {
public:
     bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<bool> prev(sum+1, 0), curr(sum+1, 0);
        prev[0] = curr[0] = true;
        if(arr[0] <= sum)prev[arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int k=1; k<=sum; k++){
                bool notTake = prev[k];
                bool take = false;
                if(arr[i] <= k) take = prev[k-arr[i]];
                curr[k] = take | notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) totalSum += nums[i];
        if(totalSum % 2) return false;
        int target = totalSum / 2;
        return isSubsetSum(nums, target);
    }
};