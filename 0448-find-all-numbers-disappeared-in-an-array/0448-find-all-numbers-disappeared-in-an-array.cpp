class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] *= -1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1); // these numbers are missing
            }
        }
        // int i = 0;
        // while(i < n){
        //     if(nums[i] != nums[nums[i]-1]){
        //         swap(nums[i], nums[nums[i]-1]);
        //     }
        //     else i++;
        // }
        // for(int i=0; i<n; i++){
        //     if(i != nums[i] - 1){
        //         ans.push_back(i+1);
        //     }
        // }
        return ans;
    }
};