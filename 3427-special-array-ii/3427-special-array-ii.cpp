class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       int n = nums.size();
        vector<bool> sp(n-1,false);

        for (int i = 0; i < n - 1; ++i) {
            sp[i]=(nums[i]%2!=nums[i + 1]%2);
        }

        vector<int> pf(n,0);
        for (int i = 1; i < n; ++i) {
            pf[i]=pf[i - 1]+(sp[i - 1] ?1:0);
        }

        vector<bool> ans;
        for (auto x : queries) {
            int s=x[0];
            int e=x[1];

            if (s==e) {
                ans.push_back(true);
                continue;
            }

            if (pf[s]-pf[e]==(s-e)) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};