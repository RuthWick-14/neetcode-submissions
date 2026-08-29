class Solution {
private:
    bool dfs(int node, int target, map<int, vector<int>>& adjacency, vector<bool>& vis) {
        if(node == target)
            return true;

        vis[node] = true;

        for(int x : adjacency[node]) {
            if(!vis[x]) {
                if(dfs(x, target, adjacency, vis))
                    return true;
            }
        }

        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        map<int, vector<int>> adjacency;

        for(int i = 0; i < n; i++) {

            int u = edges[i][0];
            int v = edges[i][1];

            vector<bool> vis(n + 1, false);

            if(dfs(u, v, adjacency, vis)) {
                return {u, v};
            }

            adjacency[u].push_back(v);
            adjacency[v].push_back(u);
        }

        return {};
    }
};
