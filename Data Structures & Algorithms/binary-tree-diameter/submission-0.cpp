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

    pair<int, int> calculateDiameter(TreeNode* root) {
        if (root == NULL) return {0, 0};
        if (root->left == NULL && root->right == NULL) {
            return {1, 0};
        }
        pair<int,int> leftAns = calculateDiameter(root->left);
        pair<int,int> rightAns = calculateDiameter(root->right);

        int depth = 1 + max(leftAns.first, rightAns.first);
        int diameterThroughThisNode = leftAns.first + rightAns.first;
        int maxDiameter = max(leftAns.second, max(rightAns.second, diameterThroughThisNode));
        return {depth, maxDiameter};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return calculateDiameter(root).second;
    }
};
