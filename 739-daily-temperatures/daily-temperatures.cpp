class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n, 0);
        stack<int> st;                      // stores indices with strictly decreasing temps

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && t[st.top()] <= t[i]) st.pop();  // equal not warmer -> pop
            if (!st.empty()) ans[i] = st.top() - i;               // distance to next warmer
            st.push(i);
        }
        return ans;
    }
};