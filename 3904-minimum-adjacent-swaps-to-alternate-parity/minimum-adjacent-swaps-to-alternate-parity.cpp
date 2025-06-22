class Solution {
public:
    int countSwaps(vector<int>& nums, int state){
        int n = nums.size();
        int minSwaps = 0, curr = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == state){
                minSwaps += abs(curr - i);
                curr += 2;
            }
        }
        return minSwaps;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int cnte = 0, cnto = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2){
                cnto++;
            }
            else cnte++;
        }
        if(abs(cnte - cnto) > 1) return -1;
        if(cnte > cnto) return countSwaps(nums, 0);
        else if(cnto > cnte) return countSwaps(nums, 1);
        else return min(countSwaps(nums, 0), countSwaps(nums, 1));
        return -1;
    }
};