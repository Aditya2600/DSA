class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<bool> poss(3001, false);
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                poss[nums[i] ^ nums[j]] = true;
            }
        }
        vector<bool> newPoss(3001, false);
        for(int i=0; i<=3000; i++){
            for(int j=0; j<n; j++){
                if(((i ^ nums[j]) <= 3000) && (poss[i ^ nums[j]])){
                    newPoss[i] = true;
                }
            }
        }
        return count(newPoss.begin(), newPoss.end(), true);
    }
};