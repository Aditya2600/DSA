#include <vector>
using namespace std;

class Solution {
public:
    vector<int> generateRow(int row) {
        long long ans = 1; // Use long long to prevent overflow
        vector<int> ansRow;
        ansRow.push_back(1); // First element is always 1
        for (int col = 1; col <= row; col++) { // Include the last element
            ans = ans * (row - col + 1) / col; // Correct the formula
            ansRow.push_back(ans);
        }
        return ansRow;
    }
    
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) { // Start from 0
            ans.push_back(generateRow(i));
        }
        return ans;
    }
};
