class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;           // FIX: last valid in nums1
        int j = n - 1;           // FIX: last in nums2
        int k = m + n - 1;       // FIX: fill position from the end

        // Place the larger of nums1[i] and nums2[j] at nums1[k], move backwards
        while (j >= 0) {         // FIX: only need to ensure nums2 left gets placed
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};