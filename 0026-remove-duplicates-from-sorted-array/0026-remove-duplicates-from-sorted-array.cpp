// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         set<int> st;
//         for (auto it : nums) {
//             st.insert(it);
//         }
//         int i = 0;
//         for (auto it : st) {
//             nums[i] = it;
//             i++;
//         }
//         return i;
//     }
// };

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                continue;
            } else {
                nums[i + 1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};