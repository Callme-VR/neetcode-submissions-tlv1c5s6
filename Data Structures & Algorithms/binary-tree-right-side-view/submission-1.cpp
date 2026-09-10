class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        // This vector will store the nodes visible
        // when we look at the tree from the right side.
        vector<int> answer;

        // If the tree is empty, there is nothing to see.
        if (root == nullptr)
            return answer;

        // We use a queue because we want to traverse
        // the tree level by level (BFS).
        queue<TreeNode*> q;

        // Start BFS by putting the root into the queue.
        q.push(root);

        // Continue until there are no more nodes to process.
        while (!q.empty()) {

            // Store the number of nodes present at the
            // current level.
            //
            // Example:
            // Level 0 -> 1 node
            // Level 1 -> 2 nodes
            // Level 2 -> 4 nodes
            int size = q.size();

            // Process all nodes of the current level.
            for (int i = 0; i < size; i++) {

                // Take the front node from the queue.
                TreeNode* node = q.front();
                q.pop();

                // The last node processed at this level
                // is the rightmost node.
                //
                // Therefore, this node will be visible
                // from the right side of the tree.
                if (i == size - 1) {
                    answer.push_back(node->val);
                }

                // Add the left child for the next level.
                if (node->left)
                    q.push(node->left);

                // Add the right child for the next level.
                if (node->right)
                    q.push(node->right);
            }
        }

        // Return the rightmost node from every level.
        return answer;
    }
};