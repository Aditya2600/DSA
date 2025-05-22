class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; ++i){
            while(nums[i] > 0 && nums[i]<=n && nums[nums[i] - 1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0; i<n; ++i){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
        // map<int, int> mp;
        // int n = nums.size();
        
        // if (n == 1 && nums[0] == 1)
        //     return 2;
        // if (n == 1 && nums[0] != 1)
        //     return 1;

        // int max_ele = *max_element(nums.begin(), nums.end());
        
        // if (max_ele < 1)
        //     return 1;

        // for (int i = 1; i <= max_ele + 1; i++) {
        //     mp[i] = 1;
        // }

        // for (int i = 0; i < n; i++) {
        //     if (mp.find(nums[i]) != mp.end()) {
        //         mp[nums[i]] = 0;
        //     }
        // }

        // for (int i = 1; i <= max_ele + 1; i++) {
        //     if (mp[i] != 0) {
        //         return i;
        //     }
        // }

        // return max_ele + 1;
    }
};

