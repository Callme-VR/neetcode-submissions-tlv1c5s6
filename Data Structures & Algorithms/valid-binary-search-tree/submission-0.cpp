class Solution {
public:

    // Check whether every node lies within its allowed range
    bool validate(TreeNode* node, long long minv, long long maxv) {

        // If there is no node, this subtree is valid
        if (node == nullptr)
            return true;

        // Current node must be strictly between minv and maxv
        // If it goes outside the range, it is NOT a valid BST
        if (node->val <= minv || node->val >= maxv)
            return false;

        // For the left subtree:
        // Every value must be smaller than current node
        //
        // For the right subtree:
        // Every value must be greater than current node
        return validate(node->left, minv, node->val) &&
               validate(node->right, node->val, maxv);
    }

    bool isValidBST(TreeNode* root) {

        // Initially root can have any value,
        // so its range is (-infinity, +infinity)
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};