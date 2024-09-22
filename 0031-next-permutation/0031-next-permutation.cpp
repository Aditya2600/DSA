#include <vector>
#include <algorithm> // For reverse and swap
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Find the rightmost ascent
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // If no ascent found, reverse to get the smallest permutation
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Find the rightmost successor to the pivot
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Reverse the sequence after the pivot
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
