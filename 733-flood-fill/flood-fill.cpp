class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
    void dfs(vector<vector<int>>& image, int currRow, int currCol, int initialColor, int newColor){
        int n = image.size();
        int m = image[0].size();
        if(currRow < 0 || currRow >= n || currCol < 0 || currCol >= m){
            return;
        }
        if(image[currRow][currCol] != initialColor)return;
        image[currRow][currCol] = newColor;
        dfs(image, currRow - 1, currCol, initialColor, newColor);
        dfs(image, currRow, currCol - 1, initialColor, newColor);
        dfs(image, currRow + 1, currCol, initialColor, newColor);
        dfs(image, currRow, currCol + 1, initialColor, newColor);
    }
};