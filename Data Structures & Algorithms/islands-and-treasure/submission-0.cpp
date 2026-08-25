class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return;
        int m = grid.size();
        int n = grid[0].size();
        int INF = 2147483647;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int r_coor[] = {-1, 0, 1, 0};
        int c_coor[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r_new = r + r_coor[i];
                int c_new = c + c_coor[i];

                if (r_new >= 0 && r_new < m && c_new >= 0 && c_new < n && grid[r_new][c_new] == INF) {
                    grid[r_new][c_new] = grid[r][c] + 1;
                    q.push({r_new, c_new});
                }
            }
        }
    }
};
