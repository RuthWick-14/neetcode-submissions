/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<int> res;
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root, root->val);
        return res.size();
    }

    void dfs(TreeNode* root, int maxi) {
        if(root == nullptr) return;

        if(root->val >= maxi) res.push_back(root->val);

        maxi = max(maxi, root->val);

        dfs(root->left, maxi);
        dfs(root->right, maxi);
    }
}; 
