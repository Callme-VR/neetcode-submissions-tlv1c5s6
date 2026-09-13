class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {

        // Agar node exist nahi karti
        if (root == nullptr)
            return nullptr;

        // Pehle left subtree process karo
        root->left = removeLeafNodes(root->left, target);

        // Phir right subtree process karo
        root->right = removeLeafNodes(root->right, target);

        // Check karo: kya current node leaf hai
        // aur kya uski value target ke equal hai?
        if (root->left == nullptr &&
            root->right == nullptr &&
            root->val == target) {

            return nullptr;
        }

        return root;
    }
};