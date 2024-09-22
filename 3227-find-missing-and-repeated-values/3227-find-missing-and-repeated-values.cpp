#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_set<int> seen;
        int repeating = -1, expectedSum = (n * n * (n * n + 1)) / 2;
        int actualSum = 0;

        // Iterate over the grid to find the repeating number and calculate the actual sum
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int num = grid[i][j];
                if (seen.find(num) != seen.end()) {
                    repeating = num; // Found the repeating number
                }
                seen.insert(num);
                actualSum += num; // Accumulate the sum of numbers in the grid
            }
        }

        // The missing number can be found using the difference of expected sum and actual sum
        int missing = expectedSum - (actualSum - repeating);

        return {repeating, missing};
    }
};
