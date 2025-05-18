class Solution {
public:
    // Helper to calculate digit sum
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mp;
        vector<pair<int, int>> sum;
        for(int i=0; i<n; i++){
            sum.push_back({digitSum(nums[i]), nums[i]});
            mp[nums[i]] = i;
        }

        sort(sum.begin(), sum.end());
        int swaps = 0;
        
        for(int i=0; i<n; i++){
            int curr = digitSum(nums[i]);
            if(curr != sum[i].first){
                swaps++;
                int ind = mp[sum[i].second];
                mp[nums[ind]] = i;
                mp[nums[i]] = ind;
                swap(nums[i], nums[ind]);
            }
            else if(nums[i] != sum[i].second){
                swaps++;

                int ind = mp[sum[i].second];
                 mp[nums[ind]] = i;
                mp[nums[i]] = ind;
                swap(nums[i], nums[ind]);
                }
            }
        return swaps;
        // // Create a tuple of: (digit_sum, original_index, value)
        // vector<tuple<int, int, int>> info;
        // for (int i = 0; i < n; i++) {
        //     info.emplace_back(digitSum(nums[i]), i, nums[i]);
        // }

        // // Sort by digit sum, then by value
        // sort(info.begin(), info.end(), [](const auto& a, const auto& b) {
        //     if (get<0>(a) != get<0>(b))
        //         return get<0>(a) < get<0>(b);
        //     return get<2>(a) < get<2>(b);  // sort by value if digit sums equal
        // });

        // // Build the final position map: where each original index goes
        // vector<int> indexMap(n);
        // for (int i = 0; i < n; i++) {
        //     indexMap[i] = get<1>(info[i]);
        // }

        // // Count cycles in the indexMap
        // vector<bool> visited(n, false);
        // int swaps = 0;

        // for (int i = 0; i < n; i++) {
        //     if (visited[i] || indexMap[i] == i) continue;

        //     int cycle_size = 0;
        //     int j = i;
        //     while (!visited[j]) {
        //         visited[j] = true;
        //         j = indexMap[j];
        //         cycle_size++;
        //     }
        //     swaps += (cycle_size - 1);
        // }

        // return swaps;
    }
};