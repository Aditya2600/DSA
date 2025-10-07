class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int currH = 1;
        int maxH = 1;
        for(int i=0; i<hBars.size() - 1; i++){
            if(hBars[i] + 1 == hBars[i+1]){
                currH++;
            }
            else currH = 1;
            maxH = max(maxH, currH);
        }
        int currV = 1;
        int maxV = 1;
        for(int i=0; i<vBars.size() - 1; i++){
            if(vBars[i] + 1 == vBars[i+1]){
                currV++;
            }
            else currV = 1;
            maxV = max(maxV, currV);
        }
        int side = min(maxH, maxV) + 1;
        return pow(side, 2);
    }
};