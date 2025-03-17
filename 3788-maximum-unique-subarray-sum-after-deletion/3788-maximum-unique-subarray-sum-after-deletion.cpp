class Solution {
public:
    int maxSum(vector<int>& nums) {

        set<int> st;
        for(auto it : nums){
            if(it <= 0) continue;
            st.insert(it);
            
        }
        if(st.empty()){
            return *max_element(nums.begin(), nums.end());
        }
        int ans = 0;
        for(auto x : st){
            ans += x;
        }
        return ans;

        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // int ans = nums[n-1];
        // for(int i=n-2; i>=0; i--){
        //     if(nums[i] == nums[i+1]) continue;
        //     if(nums[i] <= 0) break;
        //     ans += nums[i];
        // }
        // return ans;
    }
};