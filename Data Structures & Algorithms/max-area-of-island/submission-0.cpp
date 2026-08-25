class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int x_dir[] = {-1, 0, 1, 0};
        int y_dir[] = {0, 1, 0, -1};

        vis[i][j] = 1;
        int area = 1;
        for(int k = 0; k < 4; k++) {
            int ni = i + x_dir[k];
            int nj = j + y_dir[k];
            if(ni >= 0 && ni < grid.size() && nj >= 0 && nj < grid[0].size() && grid[ni][nj] == 1 && vis[ni][nj] == 0) {
                area += dfs(ni, nj, grid, vis);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;

        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));

        vector<pair<int, int>> coordinates;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    coordinates.push_back({i, j});
                }
            }
        }

        for(int k = 0 ; k < coordinates.size(); k++) {
            int x = coordinates[k].first;
            int y = coordinates[k].second;
            if(vis[x][y] == 0) {
                max_area = max(max_area, dfs(x, y, grid, vis));

            }
        }
        return max_area;
    }
};
