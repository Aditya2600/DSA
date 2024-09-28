class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto n : nums) {
            mp[n]++;
        }
        if (nums.size() % k != 0)
            return false;
        for (auto [h, freq] : mp) {
            if (freq == 0)
                continue;
            while (freq--) {
                for (int curr = h; curr < h + k; curr++) {
                    if (mp[curr] == 0)
                        return false;
                    mp[curr]--;
                }
            }
        }
        return true;
    }
};