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
    // int height(TreeNode* root){
    //     if(root == nullptr) return 0;
    //     int left = height(root->left);
    //     int right = height(root->right);
    //     return max(left, right) + 1;
    // }
    // int diameterOfBinaryTree(TreeNode* root) {
    //     if(root == nullptr) return 0;
    //     int leftTreeDiameter = diameterOfBinaryTree(root->left);
    //     int rightTreeDiameter = diameterOfBinaryTree(root->right);
    //     int currentNodeDiameter = height(root->left) + height(root->right);
    //     return max(leftTreeDiameter, max(rightTreeDiameter, currentNodeDiameter));
    // }

    // in this aproach we are merging our previous method but we are calculating height in the same
    // recursion call rather then making a new call
    pair<int, int> fastDiameterOfBinaryTree(TreeNode* root) {
        // if at nullptr just return (0, 0)
        if (root == nullptr) {
            // returning (diameter, height)
            return make_pair(0, 0);
        }

        // going to the left most node and getting 0 diameter and 0 height
        pair<int, int> left = fastDiameterOfBinaryTree(root->left);
        pair<int, int> right = fastDiameterOfBinaryTree(root->right);

        // just taking diamter in integers
        int leftTreeDiameter = left.first;
        int rightTreeDiameter = right.first;
        int currentNodeDiameter = left.second + right.second;

        // creating the pair that this function will return
        pair<int, int> ans;

        // putting the diameter in first value
        ans.first = max(leftTreeDiameter, max(rightTreeDiameter, currentNodeDiameter));
        // putting the height in second value
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameterOfBinaryTree(TreeNode* root) { return fastDiameterOfBinaryTree(root).first; }
};
