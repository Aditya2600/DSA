class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<int> ans(m);
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i=1; i<n; i++){
            pre[i] = pre[i-1] + nums[i];
        }
        for(int j=0; j<m; j++){
            int q = queries[j];
            int pos = upper_bound(pre.begin(), pre.end(), q) - pre.begin();
            ans[j] = pos;
        }
        return ans;
    }
};