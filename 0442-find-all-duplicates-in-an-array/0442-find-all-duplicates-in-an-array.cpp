class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       int n = nums.size();
       vector<int> ans;
        int i = 0;
        while(i < n){
            if(nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
            else i++;
        }
        for(int i=0; i<n; i++){
            if(nums[i] - 1 != i){
                ans.push_back(nums[i]);
            }
        }
        return ans;
        // vector<bool> vis(n, false);
        // vector<int> ans;
        // for(auto num : nums){
        //     if(!vis[num]){
        //         vis[num] = true;
        //     }
        //     else ans.push_back(num);        
        // }
        // return ans;

    }
};