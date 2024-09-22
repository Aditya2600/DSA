class Solution {
public:

    int rev(int n){
        int r = 0;
        while(n>0){
            r *= 10;
            r += (n%10);
            n /= 10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s;
        for(int it : nums){
            s.insert(it);
            s.insert(rev(it));
        }
        return s.size();
    }
};