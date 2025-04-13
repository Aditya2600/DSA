class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        if(sum < k) return sum;
        int fact = 1;
        int i = 1;
        int temp;
        while(sum >= fact){
            temp = fact;
            fact = k * i;
            i++;
        }
        return sum - temp;
    }
};