class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b){
             return a[1] > b[1];
            
        });
        int ans = 0;
        int remaining = truckSize;
        for(int i=0; i<n && remaining > 0; i++){
            if(remaining < boxTypes[i][0]){
                ans += remaining * boxTypes[i][1];
                remaining = 0;
                break;
            }
            else{
                ans += boxTypes[i][0] * boxTypes[i][1];
                remaining -= boxTypes[i][0];
                
            }
        }
        return ans;
    }
};