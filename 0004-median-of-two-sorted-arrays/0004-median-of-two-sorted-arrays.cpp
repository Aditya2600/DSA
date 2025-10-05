class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& ans) {
        int n = nums1.size();
        int m = nums2.size();
        ans.reserve(n+m);
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n) {
            ans.push_back(nums1[i]);
            i++;
        }
        while (j < m) {
            ans.push_back(nums2[j]);
            j++;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        merge(nums1, nums2, ans);
        double res = 0;
        int sz = ans.size();
        int mid1 = (sz / 2);
        int mid2 = ((sz / 2) - 1);
        if ((sz) % 2 == 0) {
            res = (ans[mid1] + ans[mid2]) / 2.0;
        } else {
            res = ans[mid1];
        }
        return res;
    }
};