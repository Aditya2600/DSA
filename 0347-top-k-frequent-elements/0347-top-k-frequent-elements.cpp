// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size();
//         unordered_map<int, int> freq;
//         for (auto it : nums) {
//             freq[it]++;
//         }
//         sort(nums.begin(), nums.end());
//         priority_queue<pair<int, int>, vector<pair<int, int>>,
//                        greater<pair<int, int>>>
//             pq;
//         pq.push({freq[nums[0]], nums[0]});
//         for (int i = 1; i < n; i++) {
//             if (nums[i] != nums[i-1]) {
//                 pq.push({freq[nums[i]], nums[i]});
//                 if (pq.size() > k) {
//                     pq.pop();
//                 }
//             }
//         }
//         vector<int> ans;
//         while (!pq.empty()) {
//             auto x = pq.top();
//             pq.pop();
//             ans.push_back(x.second);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto it : nums) {
            freq[it]++;
        }
        vector<vector<int>> bucket(n + 1);
        for (auto x : freq) {
            bucket[x.second].push_back(x.first);
        }
        vector<int> result;
        for (int i = n; i >= 0; i--) {
            if (bucket[i].size() == 0) {
                continue;
            }
            while (bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return result;
    }
};
