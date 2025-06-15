class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long ans = LLONG_MIN;
        if(m == 1){
            for(auto x : nums) ans = max(ans, (long long)x*x);
        }
        set<long> st;
        for(int i = m-1; i<n; i++){
            st.insert(nums[i - m + 1]);
            int mn = *(st.begin());
            int mx = *(st.rbegin());
            ans = max(ans, mn * (long long)nums[i]);
            ans = max(ans, mx * (long long)nums[i]);
        }
        return ans;
    }
};