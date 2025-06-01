class Solution {
public:
    int ncr(int n, int r) {
        int ans = 1;
        for (int i = 1; i <= min(r, n - r); i++) {
            ans = (ans * (n - i + 1)) / i;
        }
        return ans;
    }
    int uniquePaths(int m, int n) { return ncr(m + n - 2, min(m - 1, n - 1)); }
};