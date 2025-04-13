class Solution {
public:
    void fillsieve(vector<bool>& sieve){
        int n = sieve.size() - 1;
        for(int i=2; i<=sqrt(n); i++){
            for(int j=i*2; j<=n; j+=i){
                sieve[j] = 0;
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int maxnum = *max_element(nums.begin(), nums.end());
        
        vector<bool> sieve(maxnum+1, 1);
        if(maxnum > 0)sieve[0] = 0;
        if(maxnum > 1)sieve[1] = 0;
        fillsieve(sieve);
        vector<int> primes;
        for(int i=2; i<=maxnum; i++){
            if(sieve[i] == 1)primes.push_back(i);
        }
        vector<bool> taken(primes.size(), 0);
        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            for(int j=0; j<primes.size(); j++){
                if(primes[j] > ele)break;
                if(ele % primes[j] == 0) taken[j] = 1;
            }
        }
        int cnt = 0;
        for(int i=0; i<taken.size(); i++){
            if(taken[i] == 1){
                cnt++;
            }
        }
        return cnt;
    }
};