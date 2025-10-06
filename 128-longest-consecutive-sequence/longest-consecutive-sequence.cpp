// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(nums.empty()) return 0;
//         unordered_map<int, int> mp;
//         for(int i=0; i<n; i++){
//             mp[nums[i]]++;
//         }
//         int cnt = 1;
//         int maxcnt = 1;
//         for(int i=0; i<n; i++){
//             int num = nums[i];
//             while(mp[num + 1] > 0){
//                 cnt++;
//                 num++;
//                 maxcnt = max(cnt, maxcnt);
//             }
//             cnt = 1;
//         }
//         return maxcnt;
//     }
// };

// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int n = nums.size();
//         if(nums.empty()) return 0;
//         int largest = 1;
//         int last_smaller = INT_MIN;
//         int currCnt = 0;
//         sort(nums.begin(), nums.end());
//         for(int i=0; i<n; i++){
//             if(nums[i] == last_smaller + 1){
//                 currCnt += 1;
//                 last_smaller = nums[i];
//             }
//             else if(last_smaller != nums[i]){
//                 last_smaller = nums[i];
//                 currCnt = 1;
//             }
//             largest = max(largest, currCnt);
//         }
//         return largest;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty())
            return 0;
        unordered_set<int> st;
        int longest = INT_MIN;
        for (auto it : nums) {
            st.insert(it);
        }
        for (auto s : st) {
            if (st.find(s - 1) == st.end()) {
                int cnt = 1;
                while (st.find(s + 1) != st.end()) {
                    cnt++;
                    s = s + 1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};