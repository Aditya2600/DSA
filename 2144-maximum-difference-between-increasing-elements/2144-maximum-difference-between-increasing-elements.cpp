class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                maxDiff = max(maxDiff, (nums[j] - nums[i]));
            }
        }
        return (maxDiff <= 0) ? -1 : maxDiff;
    }
};