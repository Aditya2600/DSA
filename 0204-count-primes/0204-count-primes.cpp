class Solution {
public:
    void fillSieve(vector<bool>& sieve){
        int n = sieve.size();
        for(int i=2; i<sqrt(n); i++){
            for(int j=i*2; j<n; j+=i){
                sieve[j] = 0;
            }
        }
    }
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> sieve(n, 1);
        fillSieve(sieve);
        sieve[0] = 0;
        sieve[1] = 0;
        int cnt = 0;
        for(int i=2; i<n; i++){
            if(sieve[i]){
                cnt++;
            }
        }
        return cnt;
    }
};