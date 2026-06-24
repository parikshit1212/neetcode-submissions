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

    pair<int,int> checkHeightBalanced(TreeNode* root) {
        if (root == NULL) return {0,1};
        pair<int,int> left = checkHeightBalanced(root->left);
        if (!left.second) return {0, 0};
        pair<int,int> right = checkHeightBalanced(root->right);
        if (!right.second) return {0, 0};


        // Check for current node and return height with status
        int height = max(left.first, right.first) + 1;
        if (abs(left.first - right.first) <= 1) {
            return {height, 1};
        } else {
            return { height, 0};
        }

    }

    bool isBalanced(TreeNode* root) {
        pair<int,int> ans = checkHeightBalanced(root);
        return ans.second;
    }
};
