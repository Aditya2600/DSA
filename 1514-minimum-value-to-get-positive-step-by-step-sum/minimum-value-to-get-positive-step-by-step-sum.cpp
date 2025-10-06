class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        int preSum = 0;
        int mins = INT_MAX;
        for(int i=0; i<n; i++){
            preSum += nums[i];
            mins = min(mins, preSum);
        }
        return (mins < 0) ? abs(mins) + 1 : 1;
    }
};