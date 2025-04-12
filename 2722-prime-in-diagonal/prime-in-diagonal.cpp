class Solution {
public:
    bool isPrime(int num){
        if(num == 1){
            return false;
        }
        for(int i=2; i*i<=num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if((i == j) || (i == n - j - 1)){
                    if(isPrime(nums[i][j])){
                        ans = max(ans, nums[i][j]);
                    }
                }
            }
        }
        return ans;
    }
};