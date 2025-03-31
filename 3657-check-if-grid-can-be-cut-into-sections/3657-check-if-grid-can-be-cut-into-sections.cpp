class Solution {
public:
    vector<vector<int>> buildAndMergeOpen(vector<vector<int>>& rectangles, bool vertical) {
        vector<vector<int>> intervals;
        for (auto& rect : rectangles) {
            if (vertical) {
                intervals.push_back({rect[0], rect[2]});
            } else {
                intervals.push_back({rect[1], rect[3]});
            }
        }
        if (intervals.empty()) return {};

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        int prev_y = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0]>=prev_y)merged.push_back({1});
            prev_y=max(prev_y,intervals[i][1]);
        }
        return merged;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> mergedX = buildAndMergeOpen(rectangles, true);
        if (mergedX.size() >= 2) return true;

        vector<vector<int>> mergedY = buildAndMergeOpen(rectangles, false);
        if (mergedY.size() >= 2) return true;

        return false;
    }
};