class Solution {
public:
    long long ncr(int n, int r){
        if (n < r || r < 0) return 0;
        long long ans = 1;
        for(int i=1; i<=(min(r, n-r)); i++){
            ans = (ans * (n-i+1))/i;
        }
        return ans;
    }
    long long distributeCandies(int n, int limit) {
        long long all_combinations = ncr(n+2, 2);
        long long one_above_limit = 3LL * ncr(n-limit+1, 2);
        long long two_above_limit = 3LL * ncr(n-2*limit, 2);
        long long three_above_limit = ncr(n-3*limit-1, 2);

        long long invalid_combination = one_above_limit - two_above_limit + three_above_limit;
        long long valid_combination = all_combinations - invalid_combination;
        return valid_combination;

    }
};