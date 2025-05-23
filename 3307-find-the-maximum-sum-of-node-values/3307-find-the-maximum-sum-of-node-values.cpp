class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long total = 0;
        int count = 0;
        int minDiff = INT_MAX;

        for (int num : nums) {
            int x = num ^ k;
            // If applying XOR increases value, count it
            if (x > num) {
                total += x;
                count++;
            } else {
                total += num;
            }

            // Track the minimal difference caused by XOR operation
            minDiff = min(minDiff, abs(x - num));
        }

        // If odd number of beneficial XORs, one must be reverted (to keep edge pairing possible)
        if (count % 2 != 0) {
            total -= minDiff;
        }

        return total;
    }
};