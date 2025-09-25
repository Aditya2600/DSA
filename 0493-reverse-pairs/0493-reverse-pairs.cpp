class Solution {
public:
    void merge(vector<int>& arr, int lo, int mid, int hi) {
        vector<int> temp;
        int left = lo;
        int right = mid + 1;
        while (left <= mid && right <= hi) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        while (right <= hi) {
            temp.push_back(arr[right]);
            right++;
        }
        for (int i = lo; i <= hi; i++) {
            arr[i] = temp[i - lo];
        }
    }
    int countPairs(vector<int>& arr, int lo, int mid, int hi){
        int cnt = 0;
        int right = mid+1;
        for(int left = lo; left<=mid; left++){
            while(right <= hi && (long long)arr[left] > 2LL * arr[right]){
                right++;
            }
            cnt = cnt + (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int>& arr, int lo, int hi) {
        if(lo >= hi) return 0;
        int mid = lo + (hi - lo) / 2;
        int cnt = 0;
        cnt += mergeSort(arr, lo, mid);
        cnt += mergeSort(arr, mid + 1, hi);
        cnt += countPairs(arr, lo, mid, hi);
        merge(arr, lo, mid, hi);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};