// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();
//         vector<char> hash(n + 2, 0);

//         for (int x : nums) {
//             if (x >= 1 && x <= n + 1) {
//                 hash[x] = 1;
//             }
//         }
//         for (int i = 1; i <= n + 1; i++) {
//             if (!hash[i]) {
//                 return i;
//             }
//         }
//         return 0;
//     }
// };

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             if (nums[i] <= 0) {
//                 nums[i] = n + 1;
//             }
//         }
//         for(int i=0; i<n; i++){
//             if(abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0){
//                 nums[abs(nums[i]) - 1] *= -1;
//             }
//         }
//         for (int i = 0; i < n; i++) {
//             if (nums[i] > 0) {
//                 return i + 1;
//             }
//         }
//         return n+1;
//     }
// };

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++){
            while(nums[i] <= n && nums[i] >= 1 && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};