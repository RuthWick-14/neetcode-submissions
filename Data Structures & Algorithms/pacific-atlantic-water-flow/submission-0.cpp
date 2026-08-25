class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> res;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> q1;
        queue<pair<int, int>> q2;

        int r_coor[] = {-1, 0, 1, 0};
        int c_coor[] = {0, 1, 0, -1};


        for(int i = 0; i < n; i++) {
            q1.push({i, 0});
        }

        for(int j = 0; j < m; j++) {
            q1.push({0, j});
        }

        while(!q1.empty()) {
            pair<int, int> p1 = q1.front();
            q1.pop();

            int i = p1.first;
            int j = p1.second;

            if(vis[i][j])
                continue;

            vis[i][j] = true;
            pacific[i][j] = true;

            for(int k = 0; k < 4; k++) {
                int nr = i + r_coor[k];
                int nc = j + c_coor[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   !vis[nr][nc] &&
                   heights[i][j] <= heights[nr][nc]) {
                    q1.push({nr, nc});
                }
            }
        }

        for(auto &row : vis) {
            fill(row.begin(), row.end(), false);
        }

        for(int i = 0; i < n; i++) {
            q2.push({i, m - 1});
        }

        for(int j = 0; j < m; j++) {
            q2.push({n - 1, j});
        }

        while(!q2.empty()) {
            pair<int, int> p2 = q2.front();
            q2.pop();

            int i = p2.first;
            int j = p2.second;

            if(vis[i][j])
                continue;

            vis[i][j] = true;
            atlantic[i][j] = true;

            for(int k = 0; k < 4; k++) {
                int nr = i + r_coor[k];
                int nc = j + c_coor[k];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m &&
                   !vis[nr][nc] &&
                   heights[i][j] <= heights[nr][nc]) {
                    q2.push({nr, nc});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};
