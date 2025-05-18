class Solution {
public:
    int getSum(int n){
        int cnt = 0;
        while(n != 0){
            cnt += n % 10;
            n /= 10;
        }
        
        return cnt;
    }
     
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        vector<pair<int, int>> sum;
        for(int i = 0; i < n; i++){
            sum.push_back({getSum(nums[i]), nums[i]});
            mp[nums[i]]=i;
        }
        
        sort(sum.begin(),sum.end());
        
        int cnt = 0;
        
        for(int i = 0; i < n; i++){
            int curr = getSum(nums[i]);
            if(curr != sum[i].first) {
                cnt++;
                
                int ind = mp[sum[i].second];
                mp[nums[ind]] = i;
                mp[nums[i]] = ind;
                swap(nums[i], nums[ind]);
            }
            else if(nums[i] != sum[i].second){
                cnt++;
                
                int ind = mp[sum[i].second];
                mp[nums[ind]] = i;
                mp[nums[i]] = ind;
                swap(nums[i], nums[ind]);
                
            }
        }
        
        return cnt;
    }
};