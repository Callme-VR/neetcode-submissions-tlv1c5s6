class Solution {
public:

    // maxv = root se current node tak ka maximum value
    int countgoodnode(TreeNode* node, int maxv) {

        // Agar node exist nahi karti, koi good node nahi
        if (node == nullptr)
            return 0;

        int count = 0;

        // Agar current node ab tak ke maximum se
        // bada ya equal hai, toh ye Good Node hai
        if (node->val >= maxv)
            count = 1;

        // Ab current node ko maximum bana do
        maxv = max(maxv, node->val);

        // Left subtree ke Good Nodes count karo
        count += countgoodnode(node->left, maxv);

        // Right subtree ke Good Nodes count karo
        count += countgoodnode(node->right, maxv);

        return count;
    }

    int goodNodes(TreeNode* root) {

        // Root se start karte waqt maximum root ki value hai
        return countgoodnode(root, root->val);
    }
};