class Solution {
public:

    int pointsForString(string &s, string s1, int x){
        int n = s.size();
        int points = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(s1[0] == st.top() && s[i] == s1[1]){
                    points += x;
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
        }
        s = "";
        while(!st.empty()){
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin(), s.end());
        return points;
    }

    int maximumGain(string s, int x, int y) {
        string s1 = "ab", s2 = "ba";
        if(x<y){
            swap(x, y);
            swap(s1, s2);
        }
        return pointsForString(s, s1, x) + pointsForString(s, s2, y);
    }
};