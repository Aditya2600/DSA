class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, times = 0;
        // vector<int> flipped(n, 0);
        // for(int i=0; i<n; i++){
        //     if(i >= k){
        //         times -= flipped[i-k];
        //     }

        // if(nums[i] == 1 && times%2 || nums[i] == 0 && times%2 == 0){
        //     if(i + k > n) return -1;
        //     ans++;
        //     times++;
        //     flipped[i] = 1;
        // }
        // }
        // return ans;

        for (int i = 0; i < n; i++) {
            if (i >= k && nums[i - k] >= 2) { // If the effect of a past flip ends
                times--;
                nums[i - k] -= 2; // Reset it back to 0/1
            }

            if ((nums[i] + times) % 2 == 0) { // If bit is 0 (needs flipping)
                if (i + k > n) return -1; // Can't flip a full k-sized subarray
                ans++;  // Increase flip count
                times++; // Mark new flip
                nums[i] += 2; // Store flip effect
            }
        }
        return ans;
    }
};