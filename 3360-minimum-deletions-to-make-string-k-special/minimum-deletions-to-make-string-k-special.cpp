class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int i, int j, int k, vector<int>& freq){
        if (i == j || freq[j] - freq[i] <= k) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        long long removeLow = freq[i] + solve(i + 1, j, k, freq);
        long long removeHigh = freq[j] - freq[i] - k + solve(i, j - 1, k, freq);
        
        return dp[i][j] = min(removeLow, removeHigh);
    }

    int minimumDeletions(string word, int k) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;

        sort(freq.begin(), freq.end());
        dp = vector<vector<long long>>(26, vector<long long>(26, -1));
        return solve(0, 25, k, freq);
    }
};