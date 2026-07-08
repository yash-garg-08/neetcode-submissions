/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
   public:
    // Stores the total number of good nodes
    int count;

    // DFS traversal to count good nodes
    // 'maxi' keeps track of the maximum value seen
    // from the root to the current node.
    void getGood(TreeNode* root, int maxi) {
        // Base case: reached the end of a branch
        if (root == nullptr) {
            return;
        }

        // Current node is "good" if its value is
        // greater than or equal to the maximum value
        // encountered so far on the path.
        if (root->val >= maxi) {
            count++;

            // Update the maximum value for this path
            maxi = root->val;
        }

        // Recur for the left subtree
        getGood(root->left, maxi);

        // Recur for the right subtree
        getGood(root->right, maxi);
    }

    int goodNodes(TreeNode* root) {
        // Initially, the root is the maximum value
        // seen on the path.
        int maxi = root->val;

        // Initialize the answer
        count = 0;

        // Start DFS traversal
        getGood(root, maxi);

        // Return the total count of good nodes
        return count;
    }
};