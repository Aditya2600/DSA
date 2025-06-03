class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        
        vector<int> suff(n);
        suff[n-1] = satisfaction[n-1];
        int ind = 0;
        for(int i=n-2; i>=0; i--){
            suff[i] = suff[i+1] + satisfaction[i];
            if(suff[i] < 0){
                ind = i+1;
                break;
            }
            ind = i;
        }
        
        int x = 1;
        int ans = 0;
        for(int i = ind; i<n; i++){
            ans = ans + satisfaction[i]*(x);
            x++;
        }
        bool flag;
        for(auto it : satisfaction){           
            if(it < 0){
                flag = false;
            }
            else flag = true;
        }
        return flag == false ? 0 : ans;
    }
};