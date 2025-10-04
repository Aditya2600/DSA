class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        long long ans = 0;
        int mod = 1000000007;
        unordered_map<int, int> mp;
        for (int x : deliciousness) {
            for (int i = 0; i <= 21; i++) {
                int target = 1 << i;
                int need = target - x;
                auto it = mp.find(need);
                if (it != mp.end()) {
                    ans += (mp[need] % mod);
                }
            }
            mp[x]++;
        }
        return (int)(ans % mod);
    }
};