class Solution {
private:
    bool hasCycle(int node, int parent, vector<vector<int>>& adjacency, vector<int>& states) {
        states[node] = 1;

        for(int x : adjacency[node]) {
            if(x == parent)
                continue;

            if(states[x] == 1)
                return true;

            if(states[x] == 0) {
                if(hasCycle(x, node, adjacency, states)) {
                    return true;
                }
            }
        }

        states[node] = 2;
        return false;
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<vector<int>> adjacency(n, vector<int>());
        vector<int> states(n, 0);

        for(int i = 0; i < m; i++) {
            adjacency[edges[i][0]].push_back(edges[i][1]);
            adjacency[edges[i][1]].push_back(edges[i][0]);
        }

        if(hasCycle(0, -1, adjacency, states)) {
            return false;
        }

        for(int i = 0 ; i < n; i++) {
            if(states[i] == 0) {
                return false;
            }
        }
        return true;
    }
};
