class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = (int)mat.size();

        for (int r = 0; r < 4; ++r) {
            if (mat == target) return true;             // FIX-1: compare full matrix

            // rotate mat by 90° clockwise: transpose then reverse each row
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j)         // FIX-2: j=i+1; avoid double swaps
                    swap(mat[i][j], mat[j][i]);

            for (int i = 0; i < n; ++i)
                reverse(mat[i].begin(), mat[i].end());  // FIX-3: rotate every row
        }
        return false;
    }
};