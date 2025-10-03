class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        vector<int> ans(2, 0);
        int n = aliceSizes.size();
        int m = bobSizes.size();
        int sumA = 0;
        int sumB = 0;
        set<int> bob;
        for(int i=0; i<n; i++){
            sumA = aliceSizes[i] + sumA;
        }
        for(int i=0; i<m; i++){
            sumB = bobSizes[i] + sumB;
            bob.insert(bobSizes[i]);
        }
        int help = (sumB - sumA)/2;
        for(int i = 0; i<n; i++){
            if(bob.find(help + aliceSizes[i]) != bob.end()){
                ans[0] = aliceSizes[i];
                ans[1] = help + aliceSizes[i];
                break;
            }
        }
        return ans;
    }
};