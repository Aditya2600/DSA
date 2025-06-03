class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int prevSum = nums[0];
        ans[0] = nums[0];
        for(int i=1; i<n; i++){
            ans[i] = nums[i] + prevSum;
            prevSum = ans[i];
        }
        return ans;
    }
};