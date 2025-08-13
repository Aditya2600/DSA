class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int mindiff = INT_MAX;
        int closestSum = 0;
        for(int i=0; i<n; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                int diff = abs(target - sum);
                if(diff < mindiff){
                    mindiff = diff;
                    closestSum = sum;
                }
                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return target;
                }
            }
        }
        return closestSum;
    }
};