class Solution {
public:
    int preindexes = 0;

    // Inorder value -> index
    unordered_map<int, int> inordermap;

    TreeNode* buildTree(vector<int>& preorder, int left, int right) {

        // No elements left
        if (left > right)
            return nullptr;

        // Preorder ka current element = root
        int rootvalue = preorder[preindexes++];

        TreeNode* root = new TreeNode(rootvalue);

        // Inorder mein root ki position
        int rootIndex = inordermap[rootvalue];

        // Root ke left mein jo elements hain
        // woh left subtree banayenge
        root->left = buildTree(preorder, left, rootIndex - 1);

        // Root ke right mein jo elements hain
        // woh right subtree banayenge
        root->right = buildTree(preorder, rootIndex + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // Inorder ke elements ke indexes store karo
        for (int i = 0; i < inorder.size(); i++) {
            inordermap[inorder[i]] = i;
        }

        // Puri inorder range se tree construct karo
        return buildTree(preorder, 0, inorder.size() - 1);
    }
};