class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        int len = 0;
        int maxLen = 0;
        int left = 0;
        int right = 0;
        while (right < n) {
            if (freq[s[right]] < 1) {
                len = right - left + 1;
                maxLen = max(len, maxLen);
                freq[s[right]]++;
                right++;
            } else {
                freq[s[left]]--;
                left++;
            }
        }
        return maxLen;
    }
};