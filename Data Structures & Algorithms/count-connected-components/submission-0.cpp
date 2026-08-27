class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjacency, vector<int>& vis) {
        vis[node] = 1;

        for(int x : adjacency[node]) {
            if(vis[x] == 0) {
                dfs(x, adjacency, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> adjacency(n, vector<int>());
        vector<int> vis(n, 0);

        for(int i = 0; i < m; i++) {
            adjacency[edges[i][0]].push_back(edges[i][1]);
            adjacency[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                ans++;
                dfs(i, adjacency, vis);
            }
        }
        return ans;
    }
};
