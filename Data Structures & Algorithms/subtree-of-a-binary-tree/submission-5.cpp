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
    bool checkEqual(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr && q != nullptr) {
            return false;
        } else if (p != nullptr && q == nullptr) {
            return false;
        }
        bool checkLeft = checkEqual(p->left, q->left);
        bool checkRight = checkEqual(p->right, q->right);
        bool currVal = p->val == q->val;

        if (checkLeft && checkRight && currVal) {
            return true;
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (subRoot == nullptr) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }

        if (checkEqual(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
