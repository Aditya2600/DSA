class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        int cummSum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++){
            cummSum += nums[i];
            int left = cummSum - k;
            if(mp.find(left) != mp.end()){
                res += mp[left];
            }
            mp[cummSum]++;
    
        }
        return res;
    }
};