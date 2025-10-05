// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int cnt = 0;
//         int sum = 0;
//         int l = 0;

//         for (int r = 0; r < nums.size(); r++) {
//             sum += nums[r];
//             while (l <= r && sum > k) {
//                 sum -= nums[l++];
//             }
//             while (l <= r && sum == k) {
//                 cnt++;
//                 sum -= nums[l++];
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       map<int, int> mp;
       int preSum = 0;
       mp[0] = 1;
       int cnt = 0;
       for(int i=0; i<nums.size(); i++){
            preSum += nums[i];
            int exclude = preSum - k;
            if(mp.find(exclude) != mp.end()){
                cnt += mp[exclude];
            }
            mp[preSum] += 1;
       }
       return cnt;
    }
};