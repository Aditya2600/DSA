class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int remove = 0;
        int i = 0;
        int j = 0;
        int maxLen = 0;
        while(j < n){
            if(nums[j] == 0){
                remove++;
            }
            while(remove > 1){
                if(nums[i] == 0){
                    i++;
                    remove--;
                }
                else{
                    i++; 
                }                              
            }
            maxLen = max(maxLen, j-i);
            j++;
        }
        return maxLen;
    }
};