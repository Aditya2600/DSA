class Solution {
public:
    int overlap[12][12];

    int getOverlap(const string& a, const string& b) {
        int maxOverlap = 0;
        for (int i = 1; i < min(a.size(), b.size()); ++i) {
            if (a.substr(a.size() - i) == b.substr(0, i))
                maxOverlap = i;
        }
        return maxOverlap;
    }

    string shortestSuperstring(vector<string>& words) {
        int n = words.size();

        // Step 1: Build overlap matrix
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    overlap[i][j] = getOverlap(words[i], words[j]);
                }
            }
        }

        // Step 2: DP table
        vector<vector<int>> dp(1 << n, vector<int>(n, -1));
        vector<vector<int>> parent(1 << n, vector<int>(n, -1));

        // Base case
        for (int i = 0; i < n; ++i)
            dp[1 << i][i] = 0;

        // Step 3: Fill DP table
        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j))) continue; // j not in mask
                int prev_mask = mask ^ (1 << j);
                for (int i = 0; i < n; ++i) {
                    if (!(prev_mask & (1 << i))) continue;
                    int val = dp[prev_mask][i] + overlap[i][j];
                    if (val > dp[mask][j]) {
                        dp[mask][j] = val;
                        parent[mask][j] = i;
                    }
                }
            }
        }

        // Step 4: Reconstruct answer
        int maxLen = -1, last = -1;
        int finalMask = (1 << n) - 1;

        for (int i = 0; i < n; ++i) {
            if (dp[finalMask][i] > maxLen) {
                maxLen = dp[finalMask][i];
                last = i;
            }
        }

        vector<int> path;
        int mask = finalMask;
        while (last != -1) {
            path.push_back(last);
            int temp = parent[mask][last];
            mask ^= (1 << last);
            last = temp;
        }

        reverse(path.begin(), path.end());

        // Build result from path
        string res = words[path[0]];
        for (int i = 1; i < path.size(); ++i) {
            int o = overlap[path[i-1]][path[i]];
            res += words[path[i]].substr(o);
        }

        return res;
    }
};