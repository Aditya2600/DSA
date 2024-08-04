class Solution {
public:
    int robHelper(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = nums[n-1];
        int prev1 = max(nums[n-1],nums[n-2]);
        for(int i=n-3; i>=0; i--){
            int curr = max(prev2 + nums[i], 0 + prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
       vector<int> temp1,temp2;
       int n = nums.size();
       if(n == 1)return nums[0];
       for(int i=0; i<n; i++){
        if(i!=0) temp1.push_back(nums[i]);
        if(i!=n-1) temp2.push_back(nums[i]);
       }
       return max(robHelper(temp1),robHelper(temp2));
    }
};