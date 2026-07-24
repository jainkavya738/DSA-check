class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& image, int srcColor, int targetColor, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || image[i][j] != srcColor || vis[i][j]) return;

        image[i][j] = targetColor;
        vis[i][j] = true;

        dfs(i-1, j, vis, image, srcColor, targetColor, n, m);
        dfs(i+1, j, vis, image, srcColor, targetColor, n, m);
        dfs(i, j-1, vis, image, srcColor, targetColor, n, m);
        dfs(i, j+1, vis, image, srcColor, targetColor, n, m);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<bool>> vis(n, vector<bool> (m, false));

        dfs(sr, sc, vis, image, image[sr][sc], color, n, m);

        return image;
    }
};