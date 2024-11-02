class Solution {
public:
    long long int mod = 1e9 + 7;
    int rev(int n){
        int r = 0;
        while(n > 0){
            r *= 10;
            r += (n%10);
            n /= 10;
        }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - rev(nums[i]);
        }
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){
                count = (count + mp[nums[i]]) % mod;
            }
            mp[nums[i]]++;
        }
        return count;
    }
};