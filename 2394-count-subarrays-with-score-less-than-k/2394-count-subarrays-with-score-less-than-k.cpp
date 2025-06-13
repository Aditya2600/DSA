class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n = nums.size(), sum = 0, i = 0, j = 0, res = 0, score = 0;
        while (j < n) {
            sum += nums[j];
            score = sum * (j-i+1);
            while (score >= k && i<=j) {
                score = sum / (j-i+1);
                sum -= nums[i];
                score = sum * ((j-i+1) - 1);
                i++;
            }
            if((j-i+1) > 0)score = score / (j-i+1);
            res += (j-i+1);
            j++;
        }
    return res;
    }
};