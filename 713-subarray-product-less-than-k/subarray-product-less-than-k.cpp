class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size(), prod = 1, i = 0, j = 0, ans = 0;
        
        while(j<n){
            prod *= nums[j];
            while(prod >= k && i<=j){
                prod /= nums[i];
                i++;
            }
            ans += (j-i+1);
            j++;
        }
        return ans;
    }
};