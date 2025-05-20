class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n > 0){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;

        sort(v.begin(), v.end(), [&](int a, int b){
            int sumA = getSum(a);
            int sumB = getSum(b);
            if(sumA == sumB) return a<b;
            return sumA < sumB;
        });
        unordered_map<int, int> mp;
        for(int i=0; i<n; ++i){
            mp[nums[i]] = i;
        }
        int count = 0;
        vector<bool> vis(n, false);

        for(int i=0; i<n; i++){
            if(vis[i] || v[i] == nums[i]) continue;

            int cycle_size = 0;
            int j = i;

            while(!vis[j]){
                vis[j] = true;
                j = mp[v[j]];
                cycle_size++;
            }

            if(cycle_size > 1){
                count += cycle_size - 1;
            }
        }
        return count;
    }
};