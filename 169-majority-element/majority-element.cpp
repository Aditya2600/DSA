// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         int n = nums.size();
//         int ans = 0;
//         for(int i=0; i<n; i++){
//             mp[nums[i]]++;
//             if(mp[nums[i]] > n/2){
//                 ans = nums[i];
//             }
//         }
//     return ans;
//     }
// };
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int ele;
       int cnt = 0;
       for(int i=0; i<nums.size(); i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(nums[i] == ele){
                cnt++;
            }
            else{
                cnt--;
            }
       }
       int cnt1 = 0;
       for(int i=0; i<nums.size(); i++){
            if(nums[i] == ele){
                cnt1++;
            }
       }
       if(cnt1 > nums.size()/2){
        return ele;
       }
       return -1;
    }
};