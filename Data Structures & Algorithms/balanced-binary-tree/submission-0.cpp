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
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // Calculate left and right heights
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Left subtree is already unbalanced
        if (leftHeight == -1) {
            return -1;
        }

        // Right subtree is already unbalanced
        if (rightHeight == -1) {
            return -1;
        }

        // Current node is unbalanced
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);

        // 
    }
    bool isBalanced(TreeNode* root) { return height(root) != -1; }
};
