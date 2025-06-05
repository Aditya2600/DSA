class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        for(int mask = 1; mask < ((1<<nums.size())-2); mask++){
            long long prod_0 = 1, prod_1 = 1;
            for(int i=0; i<nums.size(); i++){
                if(mask & (1<<i)){
                    prod_0 *= nums[i];
                }
                else{
                    prod_1 *= nums[i];
                }
                if(prod_0 > target || prod_1 > target){
                    break;
                }
                }
                if(prod_0 == prod_1 && prod_0 == target){
                    return true;
            }
        }
        return false;
    }
};