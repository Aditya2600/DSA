#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long int mod = 1e9 + 7;

    // Function to reverse an integer
    int rev(int n) {
        int r = 0;
        while (n > 0) {
            r = r * 10 + (n % 10);
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> freq;
        long long count = 0;

        // Calculate the difference for each number and populate the frequency map
        for (int i = 0; i < nums.size(); ++i) {
            int diff = nums[i] - rev(nums[i]);
            // Add current count of 'diff' to result as those many pairs can be made with this new occurrence
            if (freq.find(diff) != freq.end()) {
                count = (count + freq[diff]) % mod;
            }
            // Increment frequency of this diff
            freq[diff]++;
        }

        return count;
    }
};
