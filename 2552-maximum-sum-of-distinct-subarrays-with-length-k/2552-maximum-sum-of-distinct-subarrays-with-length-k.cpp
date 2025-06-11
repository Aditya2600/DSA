class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < k) return 0;
        long long currSum = 0;
        long long maxSum = 0;
        unordered_map<int, int> freq;
        for(int i=0; i<n; i++){
            currSum += nums[i];
            freq[nums[i]]++;
            if(i >= k-1){
                if(freq.size() == k){
                    maxSum = max(maxSum, currSum);
                }
                currSum -= nums[i-k+1];
                freq[nums[i-k+1]]--;
                if(freq[nums[i-k+1]] == 0){
                    freq.erase(nums[i-k+1]);
                }
            }
        }
        return maxSum;
    }
};