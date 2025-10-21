class Solution {
public:
    using p = pair<int, pair<int, int>>;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();

        priority_queue<p, vector<p>, greater<p>> pq;
        int sum = nums1[0] + nums2[0];
        pq.push({sum, {0, 0}});
        set<pair<int, int>> vis;
        vis.insert({0, 0});
        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i], nums2[j]});

            if(i + 1 < n && vis.find({i+1, j}) == vis.end()){
                sum = nums1[i+1] + nums2[j];
                pq.push({sum, {i+1, j}});
                vis.insert({i+1, j});
            }
            if(j + 1 < m && vis.find({i, j+1}) == vis.end()){
                sum = nums1[i] + nums2[j+1];
                pq.push({sum, {i, j+1}});
                vis.insert({i, j+1});
            }
        }
        return ans;
    }
};