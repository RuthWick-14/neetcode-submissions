class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> q;

        int r_coor[] = {-1, 0, 1, 0};
        int c_coor[] = {0, 1, 0, -1};


        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O') q.push({i, 0});
            if(board[i][m-1] == 'O') q.push({i, m-1});
        }

        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O') q.push({0, j});
            if(board[n-1][j] == 'O') q.push({n-1, j});
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            vis[r][c] = true;

            for(int i = 0; i < 4; i++) {
                int r_new = r + r_coor[i];
                int c_new = c + c_coor[i];
                if(r_new>=0 && r_new<n && c_new>=0 && c_new<m && board[r_new][c_new] == 'O' && !vis[r_new][c_new]) {
                    q.push({r_new, c_new});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};
