class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int r = robot.size();
        int f = factory.size();
        
        // Sort robot and factory by their positions
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        // DP table to store minimum total distances
        vector<vector<long long>> dp(r + 1, vector<long long>(f + 1, LLONG_MAX));
        dp[0][0] = 0;  // No robots and no factories means zero distance

        // Bottom-up DP approach
        for (int j = 1; j <= f; j++) {
            dp[0][j] = 0;  // If there are no robots, the distance is zero
            int factory_pos = factory[j-1][0];
            int factory_cap = factory[j-1][1];
            
            for (int i = 1; i <= r; i++) {
                // Case where we skip this factory
                dp[i][j] = dp[i][j - 1];

                // Case where we assign robots to this factory
                long long total_distance = 0;
                for (int k = 1; k <= factory_cap && k <= i; k++) {
                    total_distance += abs(robot[i - k] - factory_pos);
                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + total_distance);
                    }
                }
            }
        }
        
        return dp[r][f];
    }
};
