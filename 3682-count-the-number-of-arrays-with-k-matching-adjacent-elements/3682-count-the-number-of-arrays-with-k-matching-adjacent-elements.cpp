#include <vector>
using namespace std;

class Solution {
    int mod = 1000000007;
    vector<long long> fact, invFact;
public:
    void precomputeFactorials(int n) {
        fact.resize(n + 1, 1);
        invFact.resize(n + 1, 1);
        
        for (int i = 2; i <= n; i++) 
            fact[i] = (fact[i - 1] * i) % mod;
        
        invFact[n] = modExp(fact[n], mod - 2, mod);
        for (int i = n - 1; i >= 0; i--) 
            invFact[i] = (invFact[i + 1] * (i + 1)) % mod;
    }

    long long ncr(int n, int r) {
        if (r < 0 || r > n) return 0;
        return (((fact[n] * invFact[r]) % mod) * invFact[n - r]) % mod;
    }

    long long modExp(long long x, long long y, int m) {
        long long res = 1;
        while (y > 0) {
            if (y & 1) res = (res * x) % m;
            x = (x * x) % m;
            y >>= 1;
        }
        return res;
    }

    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials(n - 1);
        
        int b = n - k; // Number of distinct groups
        if (b <= 0) return 0;
        
        long long c = ncr(n - 1, b - 1); // Ways to choose partitions
        long long ans = modExp(m - 1, b - 1, mod); // Ways to color the partitions
        ans = (ans * m) % mod; // Choose color for first partition
        ans = (ans * c) % mod; // Multiply with combinations
        
        return (int) ans;
    }
};