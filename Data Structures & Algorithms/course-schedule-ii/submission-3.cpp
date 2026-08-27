class Solution {
private:
    bool cycle = false;

    void dfs(int node, vector<vector<int>>& adj, vector<int>& state, vector<int>& res) {
        if(state[node] == 1) {
            cycle = true;
            return;
        }

        if(state[node] == 2)
            return;

        state[node] = 1;

        for(int neighbour : adj[node]) {
            dfs(neighbour, adj, state, res);

            if(cycle)
                return;
        }

        state[node] = 2;
        res.push_back(node);
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> adjacency(numCourses, vector<int>());
        vector<int> res;
        vector<int> state(numCourses, 0);

        for(int i = 0; i < n; i++) {
            adjacency[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(state[i] == 0) {
                dfs(i, adjacency, state, res);

                if(cycle) return {};
            }
        }

        reverse(res.begin(), res.end());

        return res;

    }
};
