class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i=0; i<n; i++){
            while(!st.empty() && st.top() > 0 && asteroids[i] < 0){
                if(st.top() + asteroids[i] > 0){
                    asteroids[i] = 0;
                }
                else if(st.top() + asteroids[i] < 0){
                    st.pop();
                }
                else{
                    st.pop();
                    asteroids[i] = 0;
                }
            }
            if(asteroids[i] != 0){
                st.push(asteroids[i]);
            }
        }
        int s = st.size();
        vector<int> res(s);
        int i = s-1;
        while(!st.empty()){
            res[i] = st.top();
            st.pop();
            i--;
        }
        return res;
    }
};