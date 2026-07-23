class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid, int n, int m){
        if(i >= n || j >= m || i < 0 || j < 0 || vis[i][j] || grid[i][j] != '1') return;

        vis[i][j] = true;

        //neighbors ko call kiya (top, right, left, bottom)
        dfs(i, j+1, vis, grid, n, m);  
        dfs(i, j-1, vis, grid, n, m);
        dfs(i+1, j, vis, grid, n, m);
        dfs(i-1, j, vis, grid, n, m);
    }

    int numIslands(vector<vector<char>>& grid) {
        int isLands = 0;
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool> (m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){ //count the number of connected components in the graph
                    dfs(i, j, vis, grid, n, m);  // jitni baar call kiya utne components hai
                    isLands++;
                }
            }
        }

        return isLands;
    }
};