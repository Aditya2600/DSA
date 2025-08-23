// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> ans;
//         int n = numbers.size();
//         unordered_map<int, int> mp;
//         for(int i=0; i<n; i++){
//             int req = target - numbers[i];
//             if(mp.find(req) != mp.end()){
//                ans.push_back(mp[req]+1);
//                ans.push_back(i+1);
//             }
//              mp[numbers[i]] = i;
//         }    
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int n = numbers.size();
        int i = 0;
        int j = n-1;
        while(i<j){
            int sum = numbers[i] + numbers[j];
            if(sum == target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            else if(sum > target){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};