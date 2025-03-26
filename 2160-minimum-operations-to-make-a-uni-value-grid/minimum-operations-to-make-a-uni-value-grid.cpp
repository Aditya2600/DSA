class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Flatten the 2D grid into a 1D vector
        vector<int> nums;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                nums.push_back(grid[i][j]);
            }
        }
        
        int size = nums.size();
        if(size == 1) return 0;  // If only one element, already uni-value
        
        // Sort the array to find the median
        sort(nums.begin(), nums.end());
        
        // Check if it's possible to make all elements equal
        // All elements must differ from some base by multiples of x
        for(int i = 1; i < size; i++) {
            int diff = nums[i] - nums[0];
            if(diff % x != 0) {
                return -1;
            }
        }
        
        // Use median as target to minimize operations
        int median = nums[size/2];  // For odd or even size, middle works
        long long operations = 0;
        
        // Calculate total operations needed to reach median
        for(int num : nums) {
            long long diff = abs((long long)num - median);
            operations += diff / x;
        }
        
        return (int)operations;
    }
};