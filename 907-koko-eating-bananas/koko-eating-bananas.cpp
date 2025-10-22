class Solution {
public:
    bool isValid(int k, const vector<int>& piles, int h) {
        long long hours = 0;
        for (int p : piles) {
            // ceil(p / k) = (p + k - 1) / k
            hours += (p + k - 1) / k;
            if (hours > h)
                return false; // early exit
        }
        return hours <= h;
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