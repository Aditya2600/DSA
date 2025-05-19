class Solution {
public:
    int maxKadane(vector<int>& nums){
        int n = nums.size();
        int currMax = nums[0], maxSum = nums[0];
        for(int i=1; i<n; i++){
            currMax = max(nums[i], currMax + nums[i]);
            maxSum = max(maxSum, currMax);
        }
        return maxSum;
    }
       int minKadane(vector<int>& nums){
        int n = nums.size();
        int currmin = nums[0], minSum = nums[0];
        for(int i=1; i<n; i++){
            currmin = min(nums[i], currmin + nums[i]);
            minSum = min(minSum, currmin);
        }
        return minSum;
    }

    int maxSubarraySumCircular(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int kadaneMax = maxKadane(nums);
        int kadaneMin = minKadane(nums);
        if(kadaneMax < 0){
            return kadaneMax;
        }
        return max(kadaneMax, total - kadaneMin);
        // int n = nums.size();
        // int maxSum = INT_MIN;
        // for(int i = 0; i<n; i++){
        //     int sum = 0;
        //     for(int len=0; len<n; len++){
        //         int ind = (i + len) % n;
        //         sum += nums[ind];
        //         maxSum = max(maxSum, sum);
        //     }
        // }
        // return maxSum;
    }
};