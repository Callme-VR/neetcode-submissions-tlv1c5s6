class Solution {
public:

    TreeNode* deleteNode(TreeNode* root, int key) {

        // Tree empty hai ya key nahi mili.
        if (root == nullptr) {
            return nullptr;
        }

        // Key smaller hai → left subtree mein search karo.
        if (key < root->val) {

            root->left = deleteNode(root->left, key);
        }

        // Key greater hai → right subtree mein search karo.
        else if (key > root->val) {

            root->right = deleteNode(root->right, key);
        }

        // key == root->val → node mil gaya.
        else {

            // Case 1: left child nahi hai.
            if (root->left == nullptr) {
                return root->right;
            }

            // Case 2: right child nahi hai.
            if (root->right == nullptr) {
                return root->left;
            }

            // Case 3: dono children hain.
            // Right subtree ka smallest node find karo.
            TreeNode* successor = root->right;

            while (successor->left != nullptr) {
                successor = successor->left;
            }

            // Current node ki value successor se replace karo.
            root->val = successor->val;

            // Original successor ko delete karo.
            root->right = deleteNode(root->right, successor->val);
        }

        // Updated subtree root return karo.
        return root;
    }
};