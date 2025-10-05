// class Solution {
// public:
//     void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& ans) {
//         int n = nums1.size();
//         int m = nums2.size();
//         ans.reserve(n+m);
//         int i = 0, j = 0;
//         while (i < n && j < m) {
//             if (nums1[i] < nums2[j]) {
//                 ans.push_back(nums1[i]);
//                 i++;
//             } else {
//                 ans.push_back(nums2[j]);
//                 j++;
//             }
//         }
//         while (i < n) {
//             ans.push_back(nums1[i]);
//             i++;
//         }
//         while (j < m) {
//             ans.push_back(nums2[j]);
//             j++;
//         }
//     }
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         merge(nums1, nums2, ans);
//         double res = 0;
//         int sz = ans.size();
//         int mid1 = (sz / 2);
//         int mid2 = ((sz / 2) - 1);
//         if ((sz) % 2 == 0) {
//             res = (ans[mid1] + ans[mid2]) / 2.0;
//         } else {
//             res = ans[mid1];
//         }
//         return res;
//     }
// };
class Solution {
public:
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m) return findMedianSortedArrays(nums2, nums1);
        int k = n + m;
        int lo = 0;
        int hi = n;
        int left = (n + m + 1) / 2;
        while(lo <= hi){
            int mid1 = (lo + hi) >> 1;
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1 < n) r1 = nums1[mid1];
            if(mid2 < m) r2 = nums2[mid2];
            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
            if(l1 <= r2 && l2 <= r1){
                if(k % 2 == 1){
                    return max(l1, l2);
                }
                else{
                    return (double)(max(l1,l2) + min(r1, r2)) / 2.0;
                }
            }
            else if(l1 > r2){
                hi = mid1-1;
            }
            else lo = mid1 + 1;

        }
        return 0;
    }
};