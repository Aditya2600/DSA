class Solution {
public:
    int n;
    unordered_map<int,int> mp;
    int dp[2001][2001];
    bool canCrossHelper(vector<int>& stones, int curr_stone_ind, int prevJump){
        
        // if(ind == stones.size()-1)return true;
        // for(int i=ind+1; i<stones.size(); i++){
        //     int diff = stones[i] - stones[ind];
        //     if(diff == jump-1 || diff == jump || diff == jump+1){
        //         if(canCrossHelper(stones, i, diff)){
        //             return true;
        //         }  
        //     }
            
        // }
        // return false;
        if(curr_stone_ind == n-1) return true;
        if(dp[curr_stone_ind][prevJump] != -1)return dp[curr_stone_ind][prevJump];
        bool result = false;
        for(int nextJump = prevJump - 1; nextJump <= prevJump + 1; nextJump++){
            if(nextJump > 0){
                int next_stone = nextJump + stones[curr_stone_ind];
                if(mp.find(next_stone) != mp.end()){
                    result = result || canCrossHelper(stones, mp[next_stone], nextJump);
                }
            }
        }
        return dp[curr_stone_ind][prevJump] = result;
    }
    bool canCross(vector<int>& stones) {
         n = stones.size();
        if(stones[1] != 1) return false;
        for(int i=0; i<n; i++){
            mp[stones[i]]=i;
        }
        memset(dp, -1, sizeof(dp));
        return canCrossHelper(stones,0,0);
    }
};