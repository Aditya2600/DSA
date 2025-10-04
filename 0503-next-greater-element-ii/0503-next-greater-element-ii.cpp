class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=2*n-1; i>=0; i--){
            int j = i % n;
            while(!st.empty() && st.top() <= nums[j]){
                st.pop();
            }
            if(st.empty()){
                ans[j] = -1;
            }
            else{
                ans[j] = st.top();
            }
            st.push(nums[j]);
        }
        return ans;
    }
};