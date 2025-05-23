class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int ans = 0;
        int j = 0;
        int n = nums.size();
        priority_queue<int> candidates;
        priority_queue<int, vector<int>, greater<int>> chosen;
        
        for(int i=0; i<n; i++){
            while(j < queries.size() && queries[j][0] == i){
                candidates.push(queries[j][1]);
                j++;
            }
            nums[i] -= (int)chosen.size();
            while(nums[i] > 0 && !candidates.empty() && candidates.top() >= i){
                ans++;
                chosen.push(candidates.top());
                candidates.pop();
                nums[i]--;
            }
            if(nums[i] > 0){
                return -1;
            }
            while(!chosen.empty() && chosen.top() == i){
                chosen.pop();
            }           
        }
        return queries.size() - ans;
    }
};