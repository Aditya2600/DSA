class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = nums[0];
        int len = n;
        while(j<n && i<n){
            if(sum < target && (j-i+1) == n){
                len = 0;
                break;
            }
            if(sum < target){
                j++;
                if(j == n){
                    break;
                }
                else{
                    sum += nums[j];
                }
                
            }
            if(sum >= target){
                len = min(len, j-i+1);
                sum -= nums[i];
                i++;
            }
        }
        return  len;
    }
};