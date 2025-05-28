class Solution {
public:
    int gcd(int a, int b){
        while(a > 0 && b > 0){
            if(a > b) a = a % b;
            else b = b % a;
        }
        if(a == 0) return b;
        return a;
    }
    int findGCD(vector<int>& nums) {
        int maxele = *max_element(nums.begin(), nums.end());
        int minele = *min_element(nums.begin(), nums.end());
        return gcd(maxele, minele);
    }
};