#define ll long long
class Solution {
public:
    ll mod = 1e9 + 7;
    vector<ll> fact, inv;

    ll modInv(ll x) {
        return HelpPow(x, mod - 2);
    }

    ll HelpPow(ll a, ll y) {
        ll res = 1;
        a = a % mod;
        while (y > 0) {
            if (y % 2 == 1) res = (res * a) % mod;
            y = y / 2;
            a = (a * a) % mod;
        }
        return res;
    }

    void pF(int n) {
        fact.resize(n + 1, 1);
        inv.resize(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % mod;
        }
        inv[n] = modInv(fact[n]);
        for (int i = n - 1; i >= 1; --i) {
            inv[i] = inv[i + 1] * (i + 1) % mod;
        }
    }

    ll Cmb(int n, int r) {
        if (r > n || r < 0) return 0;
        return fact[n] * inv[r] % mod * inv[n - r] % mod;
    }

    ll Helper(vector<int>& nums, int k) {
        ll ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            ans = (ans + nums[i] * Cmb(i, k - 1)) % mod;
            ans = (ans + nums[i] * Cmb(n - i - 1, k - 1)) % mod;
        }
        return ans;
    }

    int minMaxSums(vector<int>& nums, int k) {
        int n = nums.size();
        k = min(k, n);
        ll ans = 0;
        pF(n);
        for (int v = 1; v <= k; v++) {
            ans = (ans + Helper(nums, v) % mod) % mod;
        }
        return (int)ans;
    }
};