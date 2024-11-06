class Solution {
public:
int SetBits(int x){
    int cnt=0;
    for(int i=0;i<=8;i++){
        if(x & (1<<i))cnt++;
    }
    return cnt;
}
    bool canSortArray(vector<int>& nums) {
        int prev_max=0;
        int curr_min=nums[0];
        int curr_max=nums[0];
        int k=SetBits(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(SetBits(nums[i])==k){
                curr_min=min(curr_min,nums[i]);
                curr_max=max(curr_max,nums[i]);
            }
            else{
                if(curr_min<prev_max)return false;
                k=SetBits(nums[i]);
                prev_max=curr_max;
                curr_min=nums[i];
                curr_max=nums[i];
            }
        }
        return (curr_min>=prev_max);
    }
};