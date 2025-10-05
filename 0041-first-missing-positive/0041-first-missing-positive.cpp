class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<char> hash(n + 2, 0);

        for (int x : nums) {
            if (x >= 1 && x <= n + 1) {
                hash[x] = 1;
            }
        }
        for (int i = 1; i <= n + 1; i++) {
            if (!hash[i]) {
                return i;
            }
        }
        return 0;
    }
};