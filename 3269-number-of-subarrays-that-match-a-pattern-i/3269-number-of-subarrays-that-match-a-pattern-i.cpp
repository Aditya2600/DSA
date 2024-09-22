#include <vector>
using namespace std;

class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;

        // Iterate through each possible starting point in nums
        for (int i = 0; i <= n - m - 1; ++i) {
            bool match = true;

            // Check if the subarray matches the pattern
            for (int k = 0; k < m; ++k) {
                if (pattern[k] == 1 && nums[i + k + 1] <= nums[i + k]) {
                    match = false;
                    break;
                }
                else if (pattern[k] == 0 && nums[i + k + 1] != nums[i + k]) {
                    match = false;
                    break;
                }
                else if (pattern[k] == -1 && nums[i + k + 1] >= nums[i + k]) {
                    match = false;
                    break;
                }
            }

            // If matched, increase the count
            if (match) {
                count++;
            }
        }

        return count;
    }
};
