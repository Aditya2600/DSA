class Solution {
public:
    bool isValid(vector<int>& candies, long long k, int c){
        long long children = 0;
        int n = candies.size();
        for(int i=0; i < n; i++){
            children += (candies[i] / c);
            if(children >= k){
                return true;
            }
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        sort(candies.begin(), candies.end());
        int n = candies.size();
        int lo = 1;
        int hi = candies[n-1];
        while(lo <= hi){
            int mid = (hi + lo) >> 1;
            if(isValid(candies, k, mid)){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return hi;
    }
};