class Solution {
public:
    char processStr(string s, long long k) {
        long long sz = 0;
        for(auto ch : s){
            if(ch >= 'a' && ch <= 'z'){
                sz++;
            }
            else if(ch == '#'){
                sz *= 2;
            }
            else if(ch == '*'){
                sz = max(0ll, sz-1);
            }
            else{
                continue;
            }
        }
        if(sz <= k) return '.';
        reverse(s.begin(), s.end());
        for(auto ch : s){
            if(ch >= 'a' && ch <= 'z'){
                sz--;
            }
            else if(ch == '#'){
                sz /= 2;
                if(k >= sz){
                    k -= sz;
                    
                }
            }
            else if(ch == '*'){
                sz++;
            }
            else{
                k = sz-k-1;
            }
             if(sz == k){
                    return ch;
                }
        }
        return '.';
    }
};