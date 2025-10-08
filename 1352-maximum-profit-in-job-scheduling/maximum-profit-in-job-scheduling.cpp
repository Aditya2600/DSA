class Solution {
public:
    int solve(int ind, vector<vector<int>> &jobs, vector<int>& dp, vector<int>& starts){
        int n = jobs.size();
        if (ind >= n) {
            return 0;
        }
        if(dp[ind] != -1) return dp[ind];
        int endT = jobs[ind][1];
        int i = int(lower_bound(starts.begin(), starts.end(), endT) - starts.begin());

        int take = jobs[ind][2] + solve(i, jobs, dp, starts);
        int notTake = solve(ind + 1, jobs, dp, starts);
        return dp[ind] = max(take, notTake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = profit.size();
        vector<int> dp(n+1, -1);
        vector<vector<int>> jobs;
        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        vector<int> starts(n);
        for(int i=0; i<n; i++){
            starts[i] = jobs[i][0];
        }
        return solve(0, jobs, dp, starts);
    }
};