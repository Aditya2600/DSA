class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        bitset<50000> dp, mask;
        dp[0] = true;
        sort(begin(rewardValues), end(rewardValues));
        int closestSum = rewardValues.back() - 1, maskId = 0;
        for(int i=0; i < rewardValues.size() - 1; ++i){
            if(maskId < rewardValues[i]){
                while(maskId < rewardValues[i]){
                    mask[maskId++] = true;
                }
                dp |= (dp & mask) << rewardValues[i];
            }
        }

        while(!dp[closestSum]){
            --closestSum;
        }
        return rewardValues.back() + closestSum;
        // bitset<100001> dp, validPrev, mask;
        // dp[0] = 1;
        // sort(rewardValues.begin(), rewardValues.end());
        // int maskId = 0;
        // for(auto val : rewardValues){
        //     while(maskId < val) mask[maskId++] = 1;
        //     validPrev = (dp & mask);
        //     dp |= (validPrev << val);
        // }

        // int res = 1e5;
        // while(!dp[res]) --res;
        // return res;
    }
};