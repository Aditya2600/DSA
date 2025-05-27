class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            if(st.size() && (abs(st.top() - s[i]) == 1 || abs(st.top() - s[i]) == 25)){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        string ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};