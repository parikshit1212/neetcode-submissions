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

      TreeNode* buildBinaryTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &mp) {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preStart]);
        // find it in the inorder list and all the element on the left side of inorder index will go to the left subtree
        int inOrderIndex = mp[preorder[preStart]];
        int countElements = inOrderIndex - inStart;
        node->left = buildBinaryTree(preorder, preStart+1, preStart + countElements, inorder, inStart, inOrderIndex-1, mp);
        node->right = buildBinaryTree(preorder, preStart + countElements + 1, preEnd, inorder,inOrderIndex+1, inEnd, mp);
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inOrderValueIndexMap;
        for(int i = 0; i < inorder.size(); i++) {
            inOrderValueIndexMap[inorder[i]] = i;
        }
        // build now
        return buildBinaryTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inOrderValueIndexMap);
    }
};
