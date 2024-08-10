class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<vector<int>> left_sums(n + 1), right_sums(n + 1);
        
        // Generate all possible sums for both halves
        for (int i = 0; i < (1 << n); ++i) {
            int l_sum = 0, r_sum = 0, l_count = 0, r_count = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    l_sum += nums[j];
                    ++l_count;
                    r_sum += nums[j + n];
                    ++r_count;
                }
            }
            left_sums[l_count].push_back(l_sum);
            right_sums[r_count].push_back(r_sum);
        }
        
        // Sort each of the right half sums for binary search
        for (int i = 0; i <= n; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }
        
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int min_diff = abs(total_sum - 2 * left_sums[n][0]);

        // Try to minimize the difference
        for (int i = 0; i <= n; ++i) {
            for (int l_sum : left_sums[i]) {
                int target = total_sum / 2 - l_sum;
                int r_count = n - i;
                auto it = lower_bound(right_sums[r_count].begin(), right_sums[r_count].end(), target);
                
                if (it != right_sums[r_count].end()) {
                    int current_sum = l_sum + *it;
                    int current_diff = abs(total_sum - 2 * current_sum);
                    min_diff = min(min_diff, current_diff);
                }
                
                if (it != right_sums[r_count].begin()) {
                    --it;
                    int current_sum = l_sum + *it;
                    int current_diff = abs(total_sum - 2 * current_sum);
                    min_diff = min(min_diff, current_diff);
                }
            }
        }
        
        return min_diff;
    }
};
