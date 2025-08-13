class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // Optimization: sort to speed pruning
        sort(nums.begin(), nums.end());
        
        // Half split
        vector<int> left(nums.begin(), nums.begin() + n/2);
        vector<int> right(nums.begin() + n/2, nums.end());

        auto getSubsets = [](vector<int>& arr) {
            vector<vector<int>> sums(arr.size() + 1);
            int m = arr.size();
            for (int mask = 1; mask < (1 << m); mask++) {
                int sum = 0, cnt = 0;
                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        cnt++;
                    }
                }
                sums[cnt].push_back(sum);
            }
            return sums;
        };

        auto leftSums = getSubsets(left);
        auto rightSums = getSubsets(right);
        for (auto &vec : rightSums) sort(vec.begin(), vec.end());

        for (int sizeA = 1; sizeA < n; sizeA++) {
            if (totalSum * sizeA % n != 0) continue; // must be integer sum
            int targetSum = totalSum * sizeA / n;

            int leftMax = min(sizeA, (int)left.size());
            for (int lsize = 0; lsize <= leftMax; lsize++) {
                int rsize = sizeA - lsize;
                if (rsize < 0 || rsize > (int)right.size()) continue;
                for (int sumLeft : leftSums[lsize]) {
                    int need = targetSum - sumLeft;
                    if (binary_search(rightSums[rsize].begin(), rightSums[rsize].end(), need))
                        return true;
                }
            }
        }
        return false;
    }
};
