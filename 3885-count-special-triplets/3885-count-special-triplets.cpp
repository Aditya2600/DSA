class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        long long ans = 0;
        for(int i=1; i<n-1; i++){
            int target = 2*nums[i];
            if(!mp.count(target))continue;
            auto it = lower_bound(mp[target].begin(), mp[target].end(), i);
            int before = int(it - mp[target].begin());
            int after = mp[target].size() - before;
            if(target == nums[i]) after--;
            ans += (long long)before * after;
            ans %= int(1e9) + 7;
        }
        return ans;
    }
};