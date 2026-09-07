class Solution {
public:

    // Helper function to perform postorder traversal.
    void postOrder(TreeNode* root, vector<int>& result) {

        // Base case:
        // If the current node is NULL, stop recursion.
        if (root == nullptr) {
            return;
        }

        // Step 1: Traverse the left subtree.
        postOrder(root->left, result);

        // Step 2: Traverse the right subtree.
        postOrder(root->right, result);

        // Step 3: Visit the current/root node.
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        // Store the traversal result.
        vector<int> result;

        // Start traversal from the root.
        postOrder(root, result);

        // Return the final result.
        return result;
    }
};