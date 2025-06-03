class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int cntY = 0;
        for(int i=0; i<n; i++){
            if(customers[i] == 'Y'){
                cntY++;
            }
        }
        if(cntY == 0) return 0;
        vector<int> ans(n+1, cntY);
        for(int i=1; i<=n; i++){
            if(customers[i - 1] == 'Y'){
                ans[i] = ans[i-1] - 1;
            }
            else ans[i] = ans[i-1] + 1;
        }
        int ind = 0;
        int minHour = INT_MAX;
        for(int i = 0; i<=n; i++){
            if(ans[i] < minHour){
                minHour = ans[i];
                ind = i;
            }   
        }
        return ind;
    }
};