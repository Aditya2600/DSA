class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp;

        int cumSum = 0;
        mp[cumSum] = 1;  

        long long validLeftPoints = 0;
        long long result = 0;

        for (int j = 0; j < n; j++) {
            if (nums[j] == target) {
                validLeftPoints += mp[cumSum];
                cumSum += 1;
            } else {
                cumSum -= 1;
                validLeftPoints -= mp[cumSum];
            }

            mp[cumSum] += 1;
            result += validLeftPoints;
        }

        return result;
    }
};