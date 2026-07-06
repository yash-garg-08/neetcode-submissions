class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        // If the tree is empty, return an empty result.
        if (!root) return res;

        // Queue for performing level-order (BFS) traversal.
        queue<TreeNode*> q;
        q.push(root);

        // Traverse the tree level by level.
        while (!q.empty()) {
            // Number of nodes present at the current level.
            int levelSize = q.size();

            // Process all nodes of the current level.
            for (int i = 0; i < levelSize; i++) {
                // Remove the front node from the queue.
                TreeNode* node = q.front();
                q.pop();

                // Since we process nodes from left to right,
                // the last node at this level is the rightmost node.
                if (i == levelSize - 1) res.push_back(node->val);

                // Add the left child to the queue.
                if (node->left) q.push(node->left);

                // Add the right child to the queue.
                if (node->right) q.push(node->right);
            }
        }

        // Return the list of nodes visible from the right side.
        return res;
    }
};