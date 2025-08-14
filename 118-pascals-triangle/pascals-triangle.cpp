class Solution {
public:
    vector<int> generateRow(int numRows){
        int ans = 1;
        vector<int> row;
        row.push_back(1);
        for(int col=1; col<numRows; col++){
            ans = ans * (numRows-col);
            ans = ans / (col);
            row.push_back(ans);
        }
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int r = 1; r<=numRows; r++){
            ans.push_back(generateRow(r));
        }
        return ans;
    }
};