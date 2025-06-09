class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // we already count 1 as the first number

        while (k > 0) {
            long long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                // Skip entire subtree
                curr += 1;
                k -= steps;
            } else {
                // Go deeper into the subtree
                curr *= 10;
                k--;
            }
        }
        return curr;
    }

    long long countSteps(int n, long long curr, long long next) {
        long long steps = 0;
        while (curr <= n) {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
};