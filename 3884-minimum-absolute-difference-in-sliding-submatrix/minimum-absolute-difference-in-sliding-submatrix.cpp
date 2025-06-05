class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans;
        for(int i=0; i<n-k+1; i++){
            vector<int> vec;
            for(int j=0; j<m-k+1; j++){
                vector<int> submatrix;
                for(int ix = i; ix<i+k; ix++){
                    for(int jx = j; jx<j+k; jx++){
                        submatrix.push_back(grid[ix][jx]);
                    }
                }
                sort(submatrix.begin(), submatrix.end());
                submatrix.erase(unique(submatrix.begin(), submatrix.end()), submatrix.end());
                if(submatrix.size() == 1){
                    vec.push_back(0);
                    continue;
                }
                int min_diff = INT_MAX;
                for(int l=1; l<submatrix.size(); l++){
                    min_diff = min(min_diff, submatrix[l] - submatrix[l-1]);
                }
                vec.push_back(min_diff);
            }
            ans.push_back(vec);
        }
        return ans;
    }
};