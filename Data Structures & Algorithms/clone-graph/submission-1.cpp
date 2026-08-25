/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;

        queue<Node*> q;
        q.push(node);

        vector<Node*> vis(102, NULL);
        vis[node->val] = new Node(node->val);

        while(!q.empty()) {
            Node* curr = q.front();
            int value = curr->val;
            vector<Node*> neighbor = curr->neighbors;  
            q.pop();

            for(int i = 0; i < neighbor.size(); i++) {
                int neighborVal = neighbor[i]->val;

                if(vis[neighborVal] == NULL) {
                    vis[neighborVal] = new Node(neighborVal);
                    q.push(neighbor[i]);
                }
                vis[value]->neighbors.push_back(vis[neighborVal]);
            }
        }
        return vis[node->val];;
    }
};
