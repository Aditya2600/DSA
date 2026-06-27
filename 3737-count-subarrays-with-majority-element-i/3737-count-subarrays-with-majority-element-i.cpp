// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();

//         int ans = 0;
//         for (int i = 0; i < n; i++) {
//             int cnt = 0;
//             for (int j = i; j < n; j++) {
//                 if (nums[j] == target) {
//                     int sz = j - i + 1;
//                     cnt++;
//                 }
//                 int sz = j - i + 1;
//                 if (cnt > sz / 2) {
//                     ans++;
//                 }
//             }
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     int countMajoritySubarrays(vector<int>& nums, int target) {
//         int n = nums.size();
//         int subarr = 0;
//         vector<int> cummSum(n+1, 0);
//         for(int i=0; i<n; i++){
//             if(nums[i] == target){
//                 cummSum[i+1] = cummSum[i] + 1;
//             }
//             else {
//                 cummSum[i+1] = cummSum[i] - 1;
//             }
//         }
//         for(int i=1; i<n+1; i++){
//             for(int j=i; j<n+1; j++){
//                 if(cummSum[j] - cummSum[i-1] > 0){
//                     subarr++;
//                 }
//             }
//         }
//         return subarr;
//     }
// };


class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cumSum = 0;
        mp[cumSum] = 1;
        long long validLeftPoints = 0;
        long long result = 0;

        for(int j=0; j<n; j++){
            if(nums[j] == target){
                validLeftPoints += mp[cumSum];
                cumSum += 1;
            }
            else{
                cumSum -= 1;
                validLeftPoints -= mp[cumSum];
            }
            mp[cumSum] += 1;
            result += validLeftPoints;
        }
        return result;
    }
};

