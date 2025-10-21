class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (auto it : nums) {
            freq[it]++;
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({freq[nums[0]], nums[0]});
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                pq.push({freq[nums[i]], nums[i]});
                if (pq.size() > k) {
                    pq.pop();
                }
            }
        }
        vector<int> ans;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};