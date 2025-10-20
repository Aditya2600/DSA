class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int ans = nums[0];
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if((mid > 0) && ((nums[mid] == nums[mid-1] && mid % 2 == 1)) || (mid < n-1) && ((nums[mid] == nums[mid+1] && mid % 2 == 0))){
                lo = mid + 1;
            }
            else if((mid > 0) && ((nums[mid] == nums[mid-1] && mid % 2 == 0)) || (mid < n-1) && ((nums[mid] == nums[mid+1] && mid % 2 == 1))){
                hi = mid - 1;
            }
            else{
                return nums[mid];
            }
        }
        return ans;
    }
};