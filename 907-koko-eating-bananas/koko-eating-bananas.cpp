class Solution {
public:
    bool isValid(int k, vector<int> piles, int h) {
        int hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += ceil((double)piles[i] / k);
            if (hours > h)
                return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int lo = 1;
        int hi = piles[n - 1];
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (isValid(mid, piles, h)) {
                hi = mid - 1;
            } else
                lo = mid + 1;
        }
        return lo;
    }
};