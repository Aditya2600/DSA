class Solution {
public:
    // Function to find the median of two sorted arrays
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array to optimize binary search
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1); // Swap if needed
        }
        
        // Get the sizes of the two arrays
        int m = nums1.size();
        int n = nums2.size();
        
        // Initialize binary search variables: low and high indices for nums1
        int low = 0, high = m; 
        
        // Loop until the correct partition is found
        while (low <= high) {
            // Partition index for nums1
            int i = (low + high) / 2;
            // Partition index for nums2: total left half is (m + n + 1)/2
            int j = (m + n + 1) / 2 - i;
            
            // Check boundary conditions for left and right parts of nums1
            // If i == 0, it means left partition of nums1 is empty, assign minimum possible value
            int left1 = (i == 0) ? INT_MIN : nums1[i - 1];
            // If i equals m, it means right partition of nums1 is empty, assign maximum possible value
            int right1 = (i == m) ? INT_MAX : nums1[i];

            // Similarly, assign boundary values for nums2
            int left2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];
            
            // Check if partitions are valid:
            if (left1 <= right2 && left2 <= right1) {
                // Found the correct partition.
                // Now calculate median depending on whether the total length is odd or even.
                if ((m + n) % 2 == 0) {
                    // For even total elements, median is average of max(left1, left2) and min(right1, right2)
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                } else {
                    // For odd total elements, median is max(left1, left2)
                    return static_cast<double>(max(left1, left2));
                }
            } else if (left1 > right2) {
                // If left1 is too big, reduce partition index in nums1
                high = i - 1;
            } else {
                // If left2 is too big, increase partition index in nums1
                low = i + 1;
            }
        }
        
        // Should never reach here if input arrays are valid and sorted
        return 0.0;
    }
};