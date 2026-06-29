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
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int left = height(root->left);
        int right = height(root->right);
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        bool isLeftBal = isBalanced(root->left);
        bool isRightBal = isBalanced(root->right);

        int leftTreeHeight = height(root->left);
        int rightTreeHeight = height(root->right);
        int diff = abs(leftTreeHeight - rightTreeHeight) <= 1;
        if(diff && isLeftBal && isRightBal){
            return true;
        }else{
            return false;
        }
    }
};
