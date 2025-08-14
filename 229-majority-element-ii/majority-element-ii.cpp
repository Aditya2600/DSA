// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int, int> mp;
//         vector<int> ans;
//         int n = nums.size();
//         for(int i=0; i<n; i++){
//             mp[nums[i]]++;
//             if(find(ans.begin(), ans.end(), nums[i]) == ans.end() &&
//             mp[nums[i]] > n/3){
//                 ans.push_back(nums[i]);
//             }
//         }
//     return ans;
//     }
// };
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ls;
//         int min = n / 3 + 1;
//         unordered_map<int, int> mp;
//         for (int i = 0; i < n; i++) {
//             mp[nums[i]]++;
//             if (mp[nums[i]] == min) {
//                 ls.push_back(nums[i]);
//             }
//         }
//         return ls;
//     }
// };
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = INT_MIN;
        int ele2 = INT_MIN;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0; i<n; i++){
            if(cnt1 == 0 &&  ele2 != nums[i]){
                ele1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 &&  ele1 != nums[i]){
                ele2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i] == ele1){
                cnt1++;
            }
            else if(nums[i] == ele2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }

        }
        vector<int> ans;
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0; i<n; i++){
            if(ele1 == nums[i]) cnt1++;
            if(ele2 == nums[i]) cnt2++;
        }
        int mini = (int)(n/3)+1;
        if(cnt1 >= mini) ans.push_back(ele1);
        if(cnt2 >= mini) ans.push_back(ele2);
        return ans;
    }
};