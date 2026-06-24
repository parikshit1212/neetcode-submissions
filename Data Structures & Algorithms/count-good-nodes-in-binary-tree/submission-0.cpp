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

    void dfs(TreeNode* root, int &count, int maxNode) {
        if (root == NULL) return;

        if (root->val >= maxNode) {
            count++;
        }
        dfs(root->left, count, max(maxNode, root->val));
        dfs(root->right, count, max(maxNode, root->val));
    }

    int goodNodes(TreeNode* root) {
        int count = 0;
        int max = INT_MIN;
        dfs(root, count, max);
        return count;
    }
};
