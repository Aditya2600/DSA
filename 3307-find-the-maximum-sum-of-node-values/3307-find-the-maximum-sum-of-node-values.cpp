#define ll long long int

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0, cnt = 0, balikabakra = INT_MAX;
        for(auto el : nums){
            if((el ^ k) > el){
                sum += el^k;
                balikabakra = min(balikabakra, (ll)(el^k) - el);
                cnt++;
            }
            else{
                sum += el;
                balikabakra = min(balikabakra, (ll)el - (el^k));
            }
        }
        if(cnt % 2 == 0) return sum;
        return sum - balikabakra;
    }
};