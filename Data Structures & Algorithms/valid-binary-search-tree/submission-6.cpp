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
    // Recursively checks whether the subtree rooted at 'root'
    // satisfies the BST property within the range (left, right).
    bool valid(TreeNode* root, int left, int right) {
        // An empty tree is always a valid BST.
        if (root == nullptr) return true;

        // Current node's value must lie strictly between
        // the allowed lower and upper bounds.
        if (!(left < root->val && root->val < right)) return false;

        // Left subtree:
        // Values must be less than the current node's value.
        //
        // Right subtree:
        // Values must be greater than the current node's value.
        return valid(root->left, left, root->val) && valid(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        // Initially, every node is allowed to have any value
        // between INT_MIN and INT_MAX.
        return valid(root, INT_MIN, INT_MAX);
    }
};