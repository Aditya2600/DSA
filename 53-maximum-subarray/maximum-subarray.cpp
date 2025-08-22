#include <vector>
#include <limits.h> // For INT_MIN
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0; // Use long long to avoid overflow
        int maxi = INT_MIN; // Initialize to the smallest integer

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // Update maximum sum found so far
            if (sum > maxi) {
                maxi = sum;
            }

            // Reset sum if it drops below zero
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }
};
