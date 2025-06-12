class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int prevLoss = 0;
        for(int i=0; i<minutes; i++){
            if(grumpy[i] == 1){
                prevLoss += customers[i];
            }
        }
        int maxLoss = prevLoss;
        int idx = 0;
        int i = 1;
        int j = minutes;
        while(j < n){
            int currLoss = prevLoss;
            if(grumpy[i-1] == 1){
                currLoss -= customers[i-1];
            }
            if(grumpy[j] == 1){
                currLoss += customers[j];
            }
            if(currLoss > maxLoss){
                maxLoss = currLoss;
                idx = i;
            }
            prevLoss = currLoss;
            i++;
            j++;
        }
        for(int i=idx; i<idx+minutes; i++){
            grumpy[i] = 0;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            if(grumpy[i] == 0){
                ans += customers[i];
            }
        }
        return ans;
    }
};