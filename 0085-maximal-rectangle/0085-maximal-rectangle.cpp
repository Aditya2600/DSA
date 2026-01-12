class Solution {
public:
    vector<int> getNSL(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSL(n);

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                NSL[i] = -1;
            } else {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    NSL[i] = -1;
                } else {
                    NSL[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSL;
    }

    vector<int> getNSR(vector<int>& height) {
        stack<int> st;
        int n = height.size();
        vector<int> NSR(n);

        for (int i = n - 1; i >= 0; i--) {
            if (st.empty()) {
                NSR[i] = n;
            } else {
                while (!st.empty() && height[st.top()] >= height[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    NSR[i] = n;
                } else {
                    NSR[i] = st.top();
                }
            }
            st.push(i);
        }
        return NSR;
    }
    int findMaxArea(vector<int> height) {
        vector<int> NSR = getNSR(height);
        vector<int> NSL = getNSL(height);

        int n = height.size();
        vector<int> width(n);
        for(int i=0; i<n; i++){
            width[i] = NSR[i] - NSL[i] - 1;
        }
        int maxArea = 0;

        for(int i=0; i<n; i++){
            int a = width[i] * height[i];
            maxArea = max(maxArea, a);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m);
        for (int i = 0; i < m; i++) {
            height[i] = (matrix[0][i] == '1') ? 1 : 0;
        }
        int maxArea = findMaxArea(height);

        for (int row = 1; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (matrix[row][col] == '1') {
                    height[col] += 1;
                } else {
                    height[col] = 0;
                }
            }
            maxArea = max(maxArea, findMaxArea(height));
        }
        return maxArea;
    }
};