// class Solution {
// public:

//     int pointsForString(string &s, string s1, int x){
//         int n = s.size();
//         int points = 0;
//         stack<int> st;
//         for(int i=0; i<n; i++){
//             if(st.empty()){
//                 st.push(s[i]);
//             }
//             else{
//                 if(s1[0] == st.top() && s[i] == s1[1]){
//                     points += x;
//                     st.pop();
//                 }
//                 else{
//                     st.push(s[i]);
//                 }
//             }
//         }
//         s = "";
//         while(!st.empty()){
//             s.push_back(st.top());
//             st.pop();
//         }
//         reverse(s.begin(), s.end());
//         return points;
//     }

//     int maximumGain(string s, int x, int y) {
//         string s1 = "ab", s2 = "ba";
//         if(x<y){
//             swap(x, y);
//             swap(s1, s2);
//         }
//         return pointsForString(s, s1, x) + pointsForString(s, s2, y);
//     }
// };

class Solution {
public:

    int pointsForString(string &s, string s1, int x){
        int n = s.size();
        int points = 0;
        int w = 0;
        for(int r = 0; r<n; r++){
            s[w++] = s[r];
            if(w>1 && s[w-1] == s1[1] && s[w-2] == s1[0]){
                w -= 2;
                points += x;
            }
        }
        s = s.substr(0, w);
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