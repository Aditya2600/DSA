class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int prev = binarySearch(events, events[i - 1][0]);

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }

private:
    int binarySearch(vector<vector<int>>& events, int currentStart) {
        int left = 0, right = events.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < currentStart) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};
// class Solution {
// public:
//     int solve(vector<vector<int>>& events, int n, int pos, int k){
//         if(pos >= n || k == 0){
//             return 0;
//         }
//         int i;
//         for(i = pos+1; i<n; i++){
//             if(events[pos][1] < events[i][0]){
//                 break;
//             }
//         }
//         return max(solve(events, n, pos+1, k), events[pos][2] + solve(events, n, i, k-1));
//     }
//     int maxValue(vector<vector<int>>& events, int k) {
//         int n = events.size();
//         sort(events.begin(), events.end());
//         return solve(events, n, 0, k);
//     }
// };

// class Solution {
// public:
//     int solve(vector<vector<int>>& events, int n, int pos, int k, vector<vector<int>> &dp){
//         if(pos >= n || k == 0){
//             return 0;
//         }
//         if(dp[pos][k] != -1) return dp[pos][k];
//         int i;
//         vector<int> temp = {events[pos][1], INT_MAX, INT_MAX};
//         i = upper_bound(events.begin()+pos+1, events.end(), temp) - events.begin();
//         return dp[pos][k] = max(solve(events, n, pos+1, k, dp), events[pos][2] + solve(events, n, i, k-1, dp));
//     }
//     int maxValue(vector<vector<int>>& events, int k) {
//         int n = events.size();
//         vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
//         sort(events.begin(), events.end());
//         return solve(events, n, 0, k, dp);
//     }
// };