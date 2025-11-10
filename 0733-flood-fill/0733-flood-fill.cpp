class Solution {
public:
    void dfs(int sr, int sc, vector<vector<int>>& image, int color, int oldColor){
        int n = image.size();
        int m = image[0].size();
        if(sr >= n || sr < 0 || sc >= m || sc < 0 || image[sr][sc] != oldColor){
            return;
        }
        image[sr][sc] = color;
        dfs(sr + 1, sc, image, color, oldColor);
        dfs(sr , sc + 1, image, color, oldColor);
        dfs(sr, sc - 1, image, color, oldColor);
        dfs(sr - 1, sc, image, color, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int oldColor = image[sr][sc];
        if(color == oldColor) return image;
        dfs(sr, sc, image, color, oldColor);
        return image;
    }
};