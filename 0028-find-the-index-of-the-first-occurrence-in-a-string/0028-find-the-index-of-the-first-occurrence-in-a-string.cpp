#define ll long long int
#define mod 1000000007
class Solution {
public:
    ll hashValue(string string, ll Radix, ll m){
        ll ans = 0, factor = 1;
        for(ll i=m-1; i>=0; i--){
            ans += ((string[i] - 'a') * factor) % mod;
            factor = (factor * Radix) % mod;
        }
        return ans % mod;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.length(), m = needle.length();
        if(m > n) return -1;
        ll Radix = 26, MAX_WEIGHT = 1;
        for(ll i=0; i<m; i++){
            MAX_WEIGHT = (MAX_WEIGHT * Radix) %mod;
        }
            ll hashNeedle = hashValue(needle, Radix, m), hashHay = 0;
            for(ll i = 0; i <= n-m; i++){
                if(i == 0){
                    hashHay = hashValue(haystack, Radix, m);
                }else{
                    hashHay = ((hashHay * Radix) % mod - ((haystack[i-1] - 'a')*MAX_WEIGHT) % mod + (haystack[i+m-1] - 'a') + mod) % mod;
                }
                if(hashNeedle == hashHay){
                    for(ll j=0; j<m; j++){
                        if(needle[j] != haystack[j + i])break;
                        if(j == m-1) return i;
                    }
                }
            
        }
        return -1;
    }
};