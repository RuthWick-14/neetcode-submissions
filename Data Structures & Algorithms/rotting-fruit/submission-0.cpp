class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> time(n, vector<int>(m, -1));

        int r_coor[] = {-1, 0, 1, 0};
        int c_coor[] = {0, 1, 0, -1};

        int max_time = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    time[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int r_new = r + r_coor[i];
                int c_new = c + c_coor[i];

                if(r_new>=0 && r_new<n && c_new>=0 && c_new<m && grid[r_new][c_new] == 1) {
                    grid[r_new][c_new] = 2; 
                    time[r_new][c_new] = time[r][c] + 1; 
                    max_time = max(max_time, time[r_new][c_new]);
                    q.push({r_new, c_new});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return max_time;
    }
};
