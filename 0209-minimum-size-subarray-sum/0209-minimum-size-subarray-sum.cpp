class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int len = INT_MAX;
        vector<int> pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; i++) {
            int lo = i;
            int hi = n;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                int sum = pre[mid] - pre[i - 1];
                if (sum >= target) {
                    len = min(len, mid - (i - 1));
                    hi = mid - 1;
                } else
                    lo = mid + 1;
            }
        }
        if(len == INT_MAX) return 0;
    return len;
    }
    // int n = nums.size();
    // int i = 0;
    // int j = 0;
    // int sum = nums[0];
    // int len = n;
    // while(j<n && i<n){
    //     if(sum < target && (j-i+1) == n){
    //         len = 0;
    //         break;
    //     }
    //     if(sum < target){
    //         j++;
    //         if(j == n){
    //             break;
    //         }
    //         else{
    //             sum += nums[j];
    //         }

    //     }
    //     if(sum >= target){
    //         len = min(len, j-i+1);
    //         sum -= nums[i];
    //         i++;
    //     }
    // }
    // return  len;

}
;