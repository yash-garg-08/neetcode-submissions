/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Stores the final answer.
        vector<vector<int>> resArr;

        // Edge case: empty tree.
        if (root == nullptr) {
            return resArr;
        }

        // Queue used for BFS.
        queue<TreeNode*> q;
        q.push(root);

        // Continue until all nodes are processed.
        while (!q.empty()) {
            // Number of nodes currently in the queue = nodes at this level.
            int n = q.size();

            // Stores values of the current level.
            vector<int> level;

            // Process exactly 'n' nodes so that children belong to the next level.
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Store current node's value.
                level.push_back(node->val);

                // Add children to the queue for the next level.
                if (node->left) q.push(node->left);

                if (node->right) q.push(node->right);
            }

            // Current level is complete.
            resArr.push_back(level);
        }

        return resArr;
    }
};