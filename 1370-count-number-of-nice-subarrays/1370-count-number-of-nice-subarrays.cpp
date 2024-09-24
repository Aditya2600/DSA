class Solution {
public:
    int numberOfSubarraysHelper(vector<int>& nums, int k){
        int cnt = 0, sum = 0, l = 0, r = 0;
        if(k < 0) return 0;
        while(r < nums.size()){
            sum += nums[r] % 2;
            while(sum > k){
                sum = sum - nums[l] % 2;
                l++;
            }
            cnt = cnt + (r - l + 1);
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysHelper(nums, k) - numberOfSubarraysHelper(nums, k-1);
    }
};