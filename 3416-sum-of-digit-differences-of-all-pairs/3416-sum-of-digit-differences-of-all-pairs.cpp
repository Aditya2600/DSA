class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
       int sz = to_string(nums[0]).size();
        vector<vector<long long>> v(sz, vector<long long>(10, 0));
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            string s = to_string(nums[i]);
            for (int k = 0; k < sz; k++) {
                v[k][s[k] - '0']++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < sz; i++) {
            for (int k = 0; k < 10; k++) {
                for (int l = 0; l < 10; l++) {
                    if (k != l) {
                        ans += v[i][k] * v[i][l];
                    }
                }
            }
        }
        return ans/2;
    }
};