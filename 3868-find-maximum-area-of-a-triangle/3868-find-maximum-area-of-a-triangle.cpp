class Solution {
public:
    long long maxArea(vector<vector<int>>& coords) {
        long long ans = LLONG_MIN;
        unordered_map<int, set<int>> xymap, yxmap;
        set<int> allx, ally;

        for(auto i : coords){
            xymap[i[0]].insert(i[1]);
            yxmap[i[1]].insert(i[0]);

            allx.insert(i[0]);
            ally.insert(i[1]);
        }
        for(auto [x, yset] : xymap){
            if(yset.size() < 2){
                continue;
            }
            int miny = *yset.begin();
            int maxy = *yset.rbegin();
            int base = maxy - miny;

            int minx = *allx.begin();
            int maxx = *allx.rbegin();

            if(minx != x){
                ans = max(ans, 1LL * abs(x - minx) * base);
            }
            if(maxx != x){
                ans = max(ans, 1LL * abs(x - maxx) * base); 
            }
        }
        for(auto [y, xset] : yxmap){
            if(xset.size() < 2){
                continue;
            }
            int minx = *xset.begin();
            int maxx = *xset.rbegin();
            int base = maxx - minx;

            int miny = *ally.begin();
            int maxy = *ally.rbegin();

            if(miny != y){
                ans = max(ans, 1LL * abs(y - miny) * base);
            }
            if(maxy != y){
                ans = max(ans, 1LL * abs(y - maxy) * base); 
            }
        }
        return ans == LLONG_MIN ? -1 : ans;
    }
};