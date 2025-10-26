class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size();
        for(int i=0; i<n; i++){
            ans += abs(nums1[i] - nums2[i]);
        }
        int mini = 1e9;
        for(int i=0; i<n; i++){
            int l = min(nums1[i], nums2[i]);
            int r = max(nums1[i], nums2[i]);

            if(nums2[n] < l){
                mini = min(mini, l - nums2[n]);
            }
            else if(nums2[n] > r){
                mini = min(mini, nums2[n] - r);
            }
            else{
                mini = 0;
                break;
            }
        }
        ans += mini + 1;
        return ans;
    }
};