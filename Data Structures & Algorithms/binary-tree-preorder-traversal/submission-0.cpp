/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // helper function to perform the inorder tranversal
    void preorder(TreeNode* root, vector<int>& result) {
        // base case for this inorder traversal
        if (root == nullptr) {
            return;
        }

        // visit current root node
        result.push_back(root->val);
        // step1:track left subtree for traversal
        preorder(root->left, result);
        // step3:track right subtree for traversal
        preorder(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }
};