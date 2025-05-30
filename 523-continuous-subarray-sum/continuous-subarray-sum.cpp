class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> firstOcc;
        firstOcc[0] = 0;
        int pre = 0;
        for(int i=0; i<n; i++){
            pre = (pre + nums[i]) % k;
            if(firstOcc.find(pre) != firstOcc.end()){
                if((i+1 - firstOcc[pre]) >= 2) return true;
            }
            else{
                firstOcc[pre] = i+1;
            }
        }
        return false;
    }
};