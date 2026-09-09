class Solution {
public:

    // Checks whether two trees have exactly the same structure and values.
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // If both nodes are NULL, this part of both trees is identical.
        if (p == nullptr && q == nullptr) {
            return true;
        }

        // If only one node is NULL, their structures are different.
        if (p == nullptr || q == nullptr) {
            return false;
        }

        // If values are different, the trees cannot be identical.
        if (p->val != q->val) {
            return false;
        }

        // Current nodes match, so recursively compare both subtrees.
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }

    // Searches for subRoot at every possible node inside root.
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // An empty tree is considered a subtree of any tree.
        if (subRoot == nullptr)
            return true;

        // Main tree ended before finding subRoot.
        if (root == nullptr)
            return false;

        // If the tree starting at this node exactly matches subRoot, we found it.
        if (isSameTree(root, subRoot))
            return true;

        // Otherwise, search for subRoot in the left or right subtree.
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};