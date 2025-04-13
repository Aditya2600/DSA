class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int bits = 0;
        int n = nums.size();
        if(n <= 2) return n;
        while (n) {
        bits++;
        n>>= 1;
    }
    return (1 << bits);
    }
};