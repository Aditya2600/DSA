class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                int leftmost = mid;
                res[0] = leftmost;
                hi = mid-1;
                // int right = mid;
                // while (right < n && nums[right] == target) {
                //     right++;
                // }
                // while (left >= 0 && nums[left] == target) {
                //     left--;
                // }
                // res[0] = left + 1;
                // res[1] = right - 1;

                // return res;
            }
            if (nums[mid] < target) {
                lo = mid + 1;

            } else if (nums[mid] > target) {
                hi = mid - 1;
            }
        }
        lo = 0;
        hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                int rightmost = mid;
                res[1] = rightmost;
                lo = mid+1;
                // int right = mid;
                // while (right < n && nums[right] == target) {
                //     right++;
                // }
                // while (left >= 0 && nums[left] == target) {
                //     left--;
                // }
                // res[0] = left + 1;
                // res[1] = right - 1;

                // return res;
            }
            if (nums[mid] < target) {
                lo = mid + 1;

            } else if (nums[mid] > target) {
                hi = mid - 1;
            }
        }
        return res;
    }
};