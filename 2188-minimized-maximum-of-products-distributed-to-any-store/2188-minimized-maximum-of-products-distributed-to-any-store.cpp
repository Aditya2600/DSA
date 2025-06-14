class Solution {
public:
    bool canAssign(int value, int n, vector<int>& quantities){
        int cnt = 0;
        for(int i=0; i<quantities.size(); i++){
            cnt += ceil((double)quantities[i]/ value);
        }
        return cnt<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int m = quantities.size();
        int ans = INT_MAX;
        int lo = 1;
        int hi = *max_element(quantities.begin(), quantities.end());
        int mid;
        while(lo <= hi){
            mid = lo + (hi-lo)/2;
            if(canAssign(mid, n, quantities)){
                ans = min(ans, mid);
                hi = mid - 1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};