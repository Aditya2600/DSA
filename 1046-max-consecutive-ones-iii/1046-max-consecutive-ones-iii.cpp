class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int flip = 0;
        int maxLen = 0;

        while (j < n) {
            if (nums[j] == 0) flip++;

            // Shrink the window if flips exceed k
            while (flip > k) {
                if (nums[i] == 0) flip--;
                i++;
            }

            // Valid window → update maxLen
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};