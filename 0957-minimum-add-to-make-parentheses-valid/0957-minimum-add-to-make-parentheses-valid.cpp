class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int moves = 0;
        for(auto c:s){
            if(c == '('){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else{
                    moves++;
                }
            }
        }
        moves+=st.size();
        return moves;
    }
};